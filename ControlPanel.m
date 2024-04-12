function varargout = ControlPanel(varargin)

gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @ControlPanel_OpeningFcn, ...
                   'gui_OutputFcn',  @ControlPanel_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);


if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end

% End initialization code - DO NOT EDIT


% --- Executes just before ControlPanel is made visible.
function ControlPanel_OpeningFcn(hObject, eventdata, handles, varargin)
handles.output = hObject;
guidata(hObject, handles);

clc;

% --- Outputs from this function are returned to the command line.
function varargout = ControlPanel_OutputFcn(hObject, eventdata, handles) 

varargout{1} = handles.output;


% --- Executes on button press in btn_run.
function btn_run_Callback(hObject, eventdata, handles)

ModelName = 'Scara';

open_system(ModelName);

set_param(ModelName,'BlockReduction','off');
set_param(ModelName,'StopTime','inf');
set_param(ModelName,'simulationMode','normal');

set_param(ModelName,'StartFcn','1');

set_param(ModelName, 'SimulationCommand', 'start');

function btn_stop_Callback(hObject, eventdata, handles)

close;

function btn_def_Callback(hObject, eventdata, handles)

ModelName = 'Scara';

l2 = 330;
l3 = 185;

%get the angle
t1 = 0;
l1 = 0;
t2 = 0;

%xoay canh tay ben simulink
set_param([ModelName '/Slider Gain'],'Gain',num2str(t1));
set_param([ModelName '/Slider Gain1'],'Gain',num2str(l1));
set_param([ModelName '/Slider Gain2'],'Gain',num2str(t2));

MT1 = [ cos(pi/2 + t1)    -sin(pi/2 + t1)*cos(0)  sin(pi/2 + t1)*sin(0)    0;
       
       sin(pi/2 + t1)     cos(pi/2 + t1)*cos(0) -cos(pi/2 + t1)*sin(0)    0;

       0                  sin(0)                 cos(0)                   l1;

       0                  0                      0                        0];


MT2 = [ cos(0)            -sin(0)*cos(0)         sin(0)*sin(0)        l2*cos(0);

       sin(0)             cos(0)*cos(0)        -cos(0)*sin(0)        l2*sin(0);

       0                  sin(0)                cos(0)               0;

       0                  0                     0                    1];

MT3 = [ cos(t2)            -sin(t2)*cos(0)       sin(t2)*sin(0)      l3*cos(t2);

       sin(t2)             cos(t2)*cos(0)       -cos(t2)*sin(0)     l3*sin(t2);

       0                   sin(0)               cos(0)              0;

       0                   0                    0                   1];

MT = MT1*MT2*MT3;

px=MT(1,4);
py=MT(2,4);
pz=MT(3,4);

set(handles.slider_t1,'value',t1);
set(handles.slider_l1,'value',l1);
set(handles.slider_t2,'value',t2);

set(handles.edit_t1,'string',num2str(0));
set(handles.edit_l1,'string',num2str(0));
set(handles.edit_t2,'string',num2str(0));

set(handles.edit_x,'string',num2str(px));
set(handles.edit_y,'string',num2str(py));
set(handles.edit_z,'string',num2str(pz));


% --- Executes on button press in btn_rev.
function btn_rev_Callback(hObject, eventdata, handles)

% Dong hoc nghich.

ModelName = 'Scara';
global var;

ppx = get(handles.slider_Px,'value');
set(handles.edit_Px,'string',num2str(ppx));

ppy=get(handles.slider_Py,'value');
set(handles.edit_Py,'string',num2str(ppy));

ppz=get(handles.slider_Pz,'value');
set(handles.edit_Pz,'string',num2str(ppz));

set(handles.edit_x,'string',num2str(ppx));
set(handles.edit_y,'string',num2str(ppy));
set(handles.edit_z,'string',num2str(ppz));

l2 = 330;
l3 = 185;

guidata(hObject,handles);

% goc quay t2 dong hoc nghich.
c2 = (ppx^2+ppy^2-l2^2-l3^2)/(2*l2*l3);
s2 = sqrt(abs(1-c2^2));
t2 = atan2d(s2,c2);
disp(t2);

c1 = (ppy*l2+ppy*l3*c2-ppx*l3*s2)/(ppx^2+ppy^2);
s1 = -(ppx*l2+ppx*l3*c2+ppy*l3*s2)/(ppx^2+ppy^2);
t1 = atan2d(s1,c1);
disp(t1);
l1 = ppz;

set_param([ModelName '/Slider Gain'], 'Gain',num2str(t1));  
set_param([ModelName '/Slider Gain1'],'Gain',num2str(l1));
set_param([ModelName '/Slider Gain2'],'Gain',num2str(t2));

set(handles.slider_t1,'value',t1);
set(handles.slider_l1,'value',l1);
set(handles.slider_t2,'value',t2);
set(handles.edit_t1,'string',num2str(t1));
set(handles.edit_l1,'string',num2str(l1));
set(handles.edit_t2,'string',num2str(t2));



% --- Executes on slider movement.
function slider_Px_Callback(hObject, eventdata, handles)

ppx = get(handles.slider_Px,'value');
set(handles.edit_Px,'string',num2str(ppx));

function slider_Px_CreateFcn(hObject, eventdata, handles)

if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end



function edit_Px_Callback(hObject, eventdata, handles)

function edit_Px_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on slider movement.
function slider_Py_Callback(hObject, eventdata, handles)
ppy=get(handles.slider_Py,'value');
set(handles.edit_Py,'string',num2str(ppy));

function slider_Py_CreateFcn(hObject, eventdata, handles)

if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end



function edit_Py_Callback(hObject, eventdata, handles)

% --- Executes during object creation, after setting all properties.
function edit_Py_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on slider movement.
function slider_Pz_Callback(hObject, eventdata, handles)

ppz=get(handles.slider_Pz,'value');
set(handles.edit_Pz,'string',num2str(ppz));


% --- Executes during object creation, after setting all properties.
function slider_Pz_CreateFcn(hObject, eventdata, handles)
% hObject    handle to slider_Pz (see GCBO)

if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end



function edit_Pz_Callback(hObject, eventdata, handles)

function edit_Pz_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on slider movement.
function slider_t1_Callback(hObject, eventdata, handles)


ModelName = 'Scara';

l2 = 330;
l3 = 185;

%get the angle
t1=get(handles.slider_t1,'value');
set(handles.edit_t1,'string',num2str(t1));
l1=get(handles.slider_l1,'value');
set(handles.edit_l1,'string',num2str(l1));
t2=get(handles.slider_t2,'value');
set(handles.edit_t2,'string',num2str(t2));



%xoay canh tay ben simulink
set_param([ModelName '/Slider Gain'],'Gain',num2str(t1));
set_param([ModelName '/Slider Gain1'],'Gain',num2str(l1));
set_param([ModelName '/Slider Gain2'],'Gain',num2str(t2));

MT1 = [ cos(pi/2 + t1)    -sin(pi/2 + t1)*cos(0)  sin(pi/2 + t1)*sin(0)    0;
       
       sin(pi/2 + t1)     cos(pi/2 + t1)*cos(0) -cos(pi/2 + t1)*sin(0)    0;

       0                  sin(0)                 cos(0)                   l1;

       0                  0                      0                        0];


MT2 = [ cos(0)            -sin(0)*cos(0)         sin(0)*sin(0)        l2*cos(0);

       sin(0)             cos(0)*cos(0)        -cos(0)*sin(0)        l2*sin(0);

       0                  sin(0)                cos(0)               0;

       0                  0                     0                    1];

MT3 = [ cos(t2)            -sin(t2)*cos(0)       sin(t2)*sin(0)      l3*cos(t2);

       sin(t2)             cos(t2)*cos(0)       -cos(t2)*sin(0)     l3*sin(t2);

       0                   sin(0)               cos(0)              0;

       0                   0                    0                   1];

MT = MT1*MT2*MT3;

px=MT(1,4);
py=MT(2,4);
pz=MT(3,4);

set(handles.edit_x,'string',num2str(px));
set(handles.edit_y,'string',num2str(py));
set(handles.edit_z,'string',num2str(pz));



% --- Executes during object creation, after setting all properties.
function slider_t1_CreateFcn(hObject, eventdata, handles)

if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end

function edit_t1_Callback(hObject, eventdata, handles)


% --- Executes during object creation, after setting all properties.
function edit_t1_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on slider movement.
function slider_t2_Callback(hObject, eventdata, handles)


ModelName = 'Scara';

l2 = 330;
l3 = 185;

%get the angle
t1=get(handles.slider_t1,'value');
set(handles.edit_t1,'string',num2str(t1));
l1=get(handles.slider_l1,'value');
set(handles.edit_l1,'string',num2str(l1));
t2=get(handles.slider_t2,'value');
set(handles.edit_t2,'string',num2str(t2));


%xoay canh tay ben simulink
set_param([ModelName '/Slider Gain'],'Gain',num2str(t1));
set_param([ModelName '/Slider Gain1'],'Gain',num2str(l1));
set_param([ModelName '/Slider Gain2'],'Gain',num2str(t2));

MT1 = [ cos(pi/2 + t1)    -sin(pi/2 + t1)*cos(0)  sin(pi/2 + t1)*sin(0)    0;
       
       sin(pi/2 + t1)     cos(pi/2 + t1)*cos(0) -cos(pi/2 + t1)*sin(0)    0;

       0                  sin(0)                 cos(0)                   l1;

       0                  0                      0                        0];


MT2 = [ cos(0)            -sin(0)*cos(0)         sin(0)*sin(0)        l2*cos(0);

       sin(0)             cos(0)*cos(0)        -cos(0)*sin(0)        l2*sin(0);

       0                  sin(0)                cos(0)               0;

       0                  0                     0                    1];

MT3 = [ cos(t2)            -sin(t2)*cos(0)       sin(t2)*sin(0)      l3*cos(t2);

       sin(t2)             cos(t2)*cos(0)       -cos(t2)*sin(0)     l3*sin(t2);

       0                   sin(0)               cos(0)              0;

       0                   0                    0                   1];

MT = MT1*MT2*MT3;

px=MT(1,4);
py=MT(2,4);
pz=MT(3,4);

set(handles.edit_x,'string',num2str(px));
set(handles.edit_y,'string',num2str(py));
set(handles.edit_z,'string',num2str(pz));


if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end



function edit_t2_Callback(hObject, eventdata, handles)

function edit_t2_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on slider movement.
function slider_l1_Callback(hObject, eventdata, handles)


ModelName = 'Scara';

l2 = 330;
l3 = 185;

%get the angle
t1=get(handles.slider_t1,'value');
set(handles.edit_t1,'string',num2str(t1));
l1=get(handles.slider_l1,'value');
set(handles.edit_l1,'string',num2str(l1));
t2=get(handles.slider_t2,'value');
set(handles.edit_t2,'string',num2str(t2));


%xoay canh tay ben simulink
set_param([ModelName '/Slider Gain'],'Gain',num2str(t1));
set_param([ModelName '/Slider Gain1'],'Gain',num2str(l1));
set_param([ModelName '/Slider Gain2'],'Gain',num2str(t2));

MT1 = [ cos(pi/2 + t1)    -sin(pi/2 + t1)*cos(0)  sin(pi/2 + t1)*sin(0)    0;
       
       sin(pi/2 + t1)     cos(pi/2 + t1)*cos(0) -cos(pi/2 + t1)*sin(0)    0;

       0                  sin(0)                 cos(0)                   l1;

       0                  0                      0                        0];


MT2 = [ cos(0)            -sin(0)*cos(0)         sin(0)*sin(0)        l2*cos(0);

       sin(0)             cos(0)*cos(0)        -cos(0)*sin(0)        l2*sin(0);

       0                  sin(0)                cos(0)               0;

       0                  0                     0                    1];

MT3 = [ cos(t2)            -sin(t2)*cos(0)       sin(t2)*sin(0)      l3*cos(t2);

       sin(t2)             cos(t2)*cos(0)       -cos(t2)*sin(0)     l3*sin(t2);

       0                   sin(0)               cos(0)              0;

       0                   0                    0                   1];

MT = MT1*MT2*MT3;

px=MT(1,4);
py=MT(2,4);
pz=MT(3,4);

set(handles.edit_x,'string',num2str(px));
set(handles.edit_y,'string',num2str(py));
set(handles.edit_z,'string',num2str(pz));



function slider_l1_CreateFcn(hObject, eventdata, handles)

if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end


function edit_l1_Callback(hObject, eventdata, handles)

function edit_l1_CreateFcn(hObject, eventdata, handles)

if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit12_Callback(hObject, eventdata, handles)
% hObject    handle to edit12 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit12 as text
%        str2double(get(hObject,'String')) returns contents of edit12 as a double


% --- Executes during object creation, after setting all properties.
function edit12_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit12 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit13_Callback(hObject, eventdata, handles)
% hObject    handle to edit13 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit13 as text
%        str2double(get(hObject,'String')) returns contents of edit13 as a double


% --- Executes during object creation, after setting all properties.
function edit13_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit13 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit14_Callback(hObject, eventdata, handles)
% hObject    handle to edit14 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit14 as text
%        str2double(get(hObject,'String')) returns contents of edit14 as a double


% --- Executes during object creation, after setting all properties.
function edit14_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit14 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_y_Callback(hObject, eventdata, handles)
% hObject    handle to edit_y (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_y as text
%        str2double(get(hObject,'String')) returns contents of edit_y as a double


% --- Executes during object creation, after setting all properties.
function edit_y_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_y (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_z_Callback(hObject, eventdata, handles)
% hObject    handle to edit_z (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_z as text
%        str2double(get(hObject,'String')) returns contents of edit_z as a double


% --- Executes during object creation, after setting all properties.
function edit_z_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_z (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit_x_Callback(hObject, eventdata, handles)
% hObject    handle to edit_x (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit_x as text
%        str2double(get(hObject,'String')) returns contents of edit_x as a double


% --- Executes during object creation, after setting all properties.
function edit_x_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit_x (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
