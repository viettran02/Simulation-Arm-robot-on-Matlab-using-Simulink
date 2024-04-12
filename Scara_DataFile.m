% Simscape(TM) Multibody(TM) version: 7.4

% This is a model data file derived from a Simscape Multibody Import XML file using the smimport function.
% The data in this file sets the block parameter values in an imported Simscape Multibody model.
% For more information on this file, see the smimport function help page in the Simscape Multibody documentation.
% You can modify numerical values, but avoid any other changes to this file.
% Do not add code to this file. Do not edit the physical units shown in comments.

%%%VariableName:smiData


%============= RigidTransform =============%

%Initialize the RigidTransform structure array by filling in null values.
smiData.RigidTransform(7).translation = [0.0 0.0 0.0];
smiData.RigidTransform(7).angle = 0.0;
smiData.RigidTransform(7).axis = [0.0 0.0 0.0];
smiData.RigidTransform(7).ID = '';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(1).translation = [350.00000000000011 0 0];  % mm
smiData.RigidTransform(1).angle = 2.0943951023931953;  % rad
smiData.RigidTransform(1).axis = [0.57735026918962584 -0.57735026918962584 0.57735026918962584];
smiData.RigidTransform(1).ID = 'B[lk3-1:-:lk4-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(2).translation = [8.291145547900669e-13 74.999999999998479 -8.8351548299669957e-13];  % mm
smiData.RigidTransform(2).angle = 2.0943951023931935;  % rad
smiData.RigidTransform(2).axis = [0.57735026918962506 -0.57735026918962618 0.57735026918962595];
smiData.RigidTransform(2).ID = 'F[lk3-1:-:lk4-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(3).translation = [0 50.000000000000007 0];  % mm
smiData.RigidTransform(3).angle = 2.0943951023931953;  % rad
smiData.RigidTransform(3).axis = [-0.57735026918962584 -0.57735026918962584 -0.57735026918962584];
smiData.RigidTransform(3).ID = 'B[lk2-1:-:Lk1-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(4).translation = [1.0907693009251848e-13 -2.7520247962731269e-15 -5.910342249841961e-14];  % mm
smiData.RigidTransform(4).angle = 2.0943951023931944;  % rad
smiData.RigidTransform(4).axis = [-0.57735026918962529 -0.57735026918962629 -0.57735026918962573];
smiData.RigidTransform(4).ID = 'F[lk2-1:-:Lk1-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(5).translation = [-32.499999999999972 520 32.5];  % mm
smiData.RigidTransform(5).angle = 2.0943951023931953;  % rad
smiData.RigidTransform(5).axis = [-0.57735026918962584 -0.57735026918962584 0.57735026918962584];
smiData.RigidTransform(5).ID = 'B[Lk1-1:-:lk3-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(6).translation = [-32.500000000000128 207.87894779672331 -32.499999999999893];  % mm
smiData.RigidTransform(6).angle = 3.1415926535897913;  % rad
smiData.RigidTransform(6).axis = [-0.70710678118654768 -0.70710678118654746 1.3877787807814457e-17];
smiData.RigidTransform(6).ID = 'F[Lk1-1:-:lk3-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(7).translation = [61.127739088685672 62.928957541559399 419.48951440129525];  % mm
smiData.RigidTransform(7).angle = 2.5423003324846802;  % rad
smiData.RigidTransform(7).axis = [0.018181813980884122 -0.99978837434521806 0.0096243526800774935];
smiData.RigidTransform(7).ID = 'RootGround[lk2-1]';


%============= Solid =============%
%Center of Mass (CoM) %Moments of Inertia (MoI) %Product of Inertia (PoI)

%Initialize the Solid structure array by filling in null values.
smiData.Solid(4).mass = 0.0;
smiData.Solid(4).CoM = [0.0 0.0 0.0];
smiData.Solid(4).MoI = [0.0 0.0 0.0];
smiData.Solid(4).PoI = [0.0 0.0 0.0];
smiData.Solid(4).color = [0.0 0.0 0.0];
smiData.Solid(4).opacity = 0.0;
smiData.Solid(4).ID = '';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(1).mass = 3.0883793239752446;  % kg
smiData.Solid(1).CoM = [0 251.75722719192873 0];  % mm
smiData.Solid(1).MoI = [100863.86961443482 4699.5499773473348 100863.86961443482];  % kg*mm^2
smiData.Solid(1).PoI = [0 0 0];  % kg*mm^2
smiData.Solid(1).color = [0.89803921568627454 0.89803921568627454 0.89803921568627454];
smiData.Solid(1).opacity = 1;
smiData.Solid(1).ID = 'Lk1*:*Default';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(2).mass = 6.2257964775166625;  % kg
smiData.Solid(2).CoM = [66.496923389476379 48.423097016113182 0];  % mm
smiData.Solid(2).MoI = [31034.578038840482 78271.705882459471 57582.492888461769];  % kg*mm^2
smiData.Solid(2).PoI = [0 0 -652.8320187709428];  % kg*mm^2
smiData.Solid(2).color = [0.50196078431372548 0.50196078431372548 0.50196078431372548];
smiData.Solid(2).opacity = 1;
smiData.Solid(2).ID = 'lk2*:*Default';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(3).mass = 4.1284225010326603;  % kg
smiData.Solid(3).CoM = [145.97097448846966 0.46038494241962863 0.82684325790265811];  % mm
smiData.Solid(3).MoI = [8318.6707550734864 76545.17173041364 75105.455069964868];  % kg*mm^2
smiData.Solid(3).PoI = [1.5715508463421117 -27.367826061407595 -387.79053303799634];  % kg*mm^2
smiData.Solid(3).color = [0 1 1];
smiData.Solid(3).opacity = 1;
smiData.Solid(3).ID = 'lk3*:*Default';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(4).mass = 1.3434480910356885;  % kg
smiData.Solid(4).CoM = [99.035170008274079 1.3069770099504077 0];  % mm
smiData.Solid(4).MoI = [1358.3551747753197 9785.4086995549733 9581.5044161100323];  % kg*mm^2
smiData.Solid(4).PoI = [0 0 590.56050587995469];  % kg*mm^2
smiData.Solid(4).color = [0.61960784313725492 0.41176470588235292 0.20000000000000001];
smiData.Solid(4).opacity = 1;
smiData.Solid(4).ID = 'lk4*:*Default';


%============= Joint =============%
%X Revolute Primitive (Rx) %Y Revolute Primitive (Ry) %Z Revolute Primitive (Rz)
%X Prismatic Primitive (Px) %Y Prismatic Primitive (Py) %Z Prismatic Primitive (Pz) %Spherical Primitive (S)
%Constant Velocity Primitive (CV) %Lead Screw Primitive (LS)
%Position Target (Pos)

%Initialize the RevoluteJoint structure array by filling in null values.
smiData.RevoluteJoint(2).Rz.Pos = 0.0;
smiData.RevoluteJoint(2).ID = '';

smiData.RevoluteJoint(1).Rz.Pos = 85.194285370692668;  % deg
smiData.RevoluteJoint(1).ID = '[lk3-1:-:lk4-1]';

smiData.RevoluteJoint(2).Rz.Pos = 50.813902628615075;  % deg
smiData.RevoluteJoint(2).ID = '[lk2-1:-:Lk1-1]';

