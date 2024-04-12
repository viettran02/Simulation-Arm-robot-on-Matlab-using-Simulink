% Simscape(TM) Multibody(TM) version: 7.4

% This is a model data file derived from a Simscape Multibody Import XML file using the smimport function.
% The data in this file sets the block parameter values in an imported Simscape Multibody model.
% For more information on this file, see the smimport function help page in the Simscape Multibody documentation.
% You can modify numerical values, but avoid any other changes to this file.
% Do not add code to this file. Do not edit the physical units shown in comments.

%%%VariableName:smiData


%============= RigidTransform =============%

%Initialize the RigidTransform structure array by filling in null values.
smiData.RigidTransform(9).translation = [0.0 0.0 0.0];
smiData.RigidTransform(9).angle = 0.0;
smiData.RigidTransform(9).axis = [0.0 0.0 0.0];
smiData.RigidTransform(9).ID = '';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(1).translation = [0 336.00000000000006 90.000000000000028];  % mm
smiData.RigidTransform(1).angle = 3.1415926535897931;  % rad
smiData.RigidTransform(1).axis = [1 0 0];
smiData.RigidTransform(1).ID = 'B[Link1-1:-:Link2-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(2).translation = [-90.000000000000028 6.5725203057809267e-14 1.4210854715202004e-13];  % mm
smiData.RigidTransform(2).angle = 2.0943951023931957;  % rad
smiData.RigidTransform(2).axis = [0.57735026918962584 0.57735026918962573 0.57735026918962573];
smiData.RigidTransform(2).ID = 'F[Link1-1:-:Link2-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(3).translation = [0 150.00000000000003 0];  % mm
smiData.RigidTransform(3).angle = 2.0943951023931953;  % rad
smiData.RigidTransform(3).axis = [-0.57735026918962584 -0.57735026918962584 -0.57735026918962584];
smiData.RigidTransform(3).ID = 'B[Base-1:-:Link1-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(4).translation = [-4.9422272944818744e-14 2.0000000000000568 3.9955059400524246e-14];  % mm
smiData.RigidTransform(4).angle = 2.0943951023931957;  % rad
smiData.RigidTransform(4).axis = [-0.57735026918962584 -0.57735026918962584 -0.57735026918962562];
smiData.RigidTransform(4).ID = 'F[Base-1:-:Link1-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(5).translation = [90 500 -1.1102230246251565e-13];  % mm
smiData.RigidTransform(5).angle = 2.0943951023931953;  % rad
smiData.RigidTransform(5).axis = [-0.57735026918962584 -0.57735026918962584 0.57735026918962584];
smiData.RigidTransform(5).ID = 'B[Link2-1:-:Link3-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(6).translation = [90.000000000000057 -1.1013412404281553e-13 -1.3145040611561853e-13];  % mm
smiData.RigidTransform(6).angle = 2.0943951023931957;  % rad
smiData.RigidTransform(6).axis = [-0.57735026918962562 -0.57735026918962573 0.57735026918962595];
smiData.RigidTransform(6).ID = 'F[Link2-1:-:Link3-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(7).translation = [-49.999999999999936 394.99999036418643 -145.00000000000003];  % mm
smiData.RigidTransform(7).angle = 2.0943951023931953;  % rad
smiData.RigidTransform(7).axis = [0.57735026918962584 0.57735026918962584 0.57735026918962584];
smiData.RigidTransform(7).ID = 'B[Link3-1:-:Link4-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(8).translation = [1.4210854715202004e-13 120.00000000000024 -49.999999999999801];  % mm
smiData.RigidTransform(8).angle = 1.2412670766236368e-16;  % rad
smiData.RigidTransform(8).axis = [-0.95938729673538381 -0.28209220985835881 1.6796558131409674e-17];
smiData.RigidTransform(8).ID = 'F[Link3-1:-:Link4-1]';

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(9).translation = [143.83166941642619 162.84052208743839 457.24936120161908];  % mm
smiData.RigidTransform(9).angle = 0;  % rad
smiData.RigidTransform(9).axis = [0 0 0];
smiData.RigidTransform(9).ID = 'RootGround[Base-1]';


%============= Solid =============%
%Center of Mass (CoM) %Moments of Inertia (MoI) %Product of Inertia (PoI)

%Initialize the Solid structure array by filling in null values.
smiData.Solid(5).mass = 0.0;
smiData.Solid(5).CoM = [0.0 0.0 0.0];
smiData.Solid(5).MoI = [0.0 0.0 0.0];
smiData.Solid(5).PoI = [0.0 0.0 0.0];
smiData.Solid(5).color = [0.0 0.0 0.0];
smiData.Solid(5).opacity = 0.0;
smiData.Solid(5).ID = '';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(1).mass = 15.151780606458528;  % kg
smiData.Solid(1).CoM = [0.08768028214430762 190.76693221125828 -0.0073161038588582857];  % mm
smiData.Solid(1).MoI = [614194.00381606666 151653.2158303099 703305.61655284918];  % kg*mm^2
smiData.Solid(1).PoI = [3.7791956511469946 20.776682531852426 -124.08048518467997];  % kg*mm^2
smiData.Solid(1).color = [0 0 1];
smiData.Solid(1).opacity = 1;
smiData.Solid(1).ID = 'Link2*:*Default';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(2).mass = 20.055007543644461;  % kg
smiData.Solid(2).CoM = [0.0077182707239480198 83.269614640835698 31.49844629520339];  % mm
smiData.Solid(2).MoI = [425156.01548033475 499102.8305587194 340025.16514028778];  % kg*mm^2
smiData.Solid(2).PoI = [-41184.366790717351 -33.272900198735002 13.004482472525105];  % kg*mm^2
smiData.Solid(2).color = [0.25098039215686274 0.25098039215686274 0.25098039215686274];
smiData.Solid(2).opacity = 1;
smiData.Solid(2).ID = 'Base*:*Default';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(3).mass = 11.411594422423711;  % kg
smiData.Solid(3).CoM = [4.7826653303845052e-08 134.66362287708463 -123.96226291336697];  % mm
smiData.Solid(3).MoI = [315785.38281590323 69786.429373031599 292732.0177544824];  % kg*mm^2
smiData.Solid(3).PoI = [33094.11211873759 3.6587751157833316e-05 -0.00011998193633742969];  % kg*mm^2
smiData.Solid(3).color = [0 0 1];
smiData.Solid(3).opacity = 1;
smiData.Solid(3).ID = 'Link3*:*Default';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(4).mass = 1.3432015469186209;  % kg
smiData.Solid(4).CoM = [-2.625457835564036e-06 124.30900869535128 1.9769413752180954e-05];  % mm
smiData.Solid(4).MoI = [7770.5782379165876 2482.9632997026461 8294.5287438514006];  % kg*mm^2
smiData.Solid(4).PoI = [0.0020218769518116821 0.0024659139492420943 0.0019664988075003766];  % kg*mm^2
smiData.Solid(4).color = [1 1 1];
smiData.Solid(4).opacity = 1;
smiData.Solid(4).ID = 'Link4*:*Default';

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(5).mass = 14.428086494628193;  % kg
smiData.Solid(5).CoM = [-1.5021183741437258e-07 213.06933764400628 0];  % mm
smiData.Solid(5).MoI = [279204.10089560732 108767.81964617716 305871.31715972163];  % kg*mm^2
smiData.Solid(5).PoI = [-4.8407768807657811e-09 0.0012507357849020025 -0.0012121320667716458];  % kg*mm^2
smiData.Solid(5).color = [0 0 1];
smiData.Solid(5).opacity = 1;
smiData.Solid(5).ID = 'Link1*:*Default';


%============= Joint =============%
%X Revolute Primitive (Rx) %Y Revolute Primitive (Ry) %Z Revolute Primitive (Rz)
%X Prismatic Primitive (Px) %Y Prismatic Primitive (Py) %Z Prismatic Primitive (Pz) %Spherical Primitive (S)
%Constant Velocity Primitive (CV) %Lead Screw Primitive (LS)
%Position Target (Pos)

%Initialize the RevoluteJoint structure array by filling in null values.
smiData.RevoluteJoint(4).Rz.Pos = 0.0;
smiData.RevoluteJoint(4).ID = '';

smiData.RevoluteJoint(1).Rz.Pos = -17.223642773214994;  % deg
smiData.RevoluteJoint(1).ID = '[Link1-1:-:Link2-1]';

smiData.RevoluteJoint(2).Rz.Pos = 77.611508775457565;  % deg
smiData.RevoluteJoint(2).ID = '[Base-1:-:Link1-1]';

smiData.RevoluteJoint(3).Rz.Pos = -10.850383272688523;  % deg
smiData.RevoluteJoint(3).ID = '[Link2-1:-:Link3-1]';

smiData.RevoluteJoint(4).Rz.Pos = 94.099669451184809;  % deg
smiData.RevoluteJoint(4).ID = '[Link3-1:-:Link4-1]';

