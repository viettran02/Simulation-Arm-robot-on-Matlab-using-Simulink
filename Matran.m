syms l1 l2 l3 t1 t2

T1 = [ cos(pi/2 + t1)    -sin(pi/2 + t1)*cos(0)  sin(pi/2 + t1)*sin(0)    0;
       
       sin(pi/2 + t1)     cos(pi/2 + t1)*cos(0) -cos(pi/2 + t1)*sin(0)    0;

       0                  sin(0)                 cos(0)                   l1;

       0                  0                      0                        0];


T2 = [ cos(0)            -sin(0)*cos(0)         sin(0)*sin(0)        l2*cos(0);

       sin(0)             cos(0)*cos(0)        -cos(0)*sin(0)        l2*sin(0);

       0                  sin(0)                cos(0)               0;

       0                  0                     0                    1];

T3 = [ cos(t2)            -sin(t2)*cos(0)       sin(t2)*sin(0)      l3*cos(t2);

       sin(t2)             cos(t2)*cos(0)       -cos(t2)*sin(0)     l3*sin(t2);

       0                   sin(0)               cos(0)              0;

       0                   0                    0                   1];


simplify(T3)
