xof 0303txt 0032

Frame Root {
  FrameTransformMatrix {
     1.000000, 0.000000, 0.000000, 0.000000,
     0.000000,-0.000000, 1.000000, 0.000000,
     0.000000, 1.000000, 0.000000, 0.000000,
     0.000000, 0.000000, 0.000000, 1.000000;;
  }
  Frame Wall1 {
    FrameTransformMatrix {
      -0.000000, 0.000000,-2.500000, 0.000000,
       0.000000, 2.500000, 0.000000, 0.000000,
       0.150000, 0.000000,-0.000000, 0.000000,
       0.000000, 0.000000, 0.000000, 1.000000;;
    }
    Mesh { // Wall1 mesh
      24;
      -1.000000;-1.000000;-1.000000;,
      -1.000000;-1.000000; 1.000000;,
      -1.000000; 1.000000; 1.000000;,
      -1.000000; 1.000000;-1.000000;,
      -1.000000; 1.000000;-1.000000;,
      -1.000000; 1.000000; 1.000000;,
       1.000000; 1.000000; 1.000000;,
       1.000000; 1.000000;-1.000000;,
       1.000000; 1.000000;-1.000000;,
       1.000000; 1.000000; 1.000000;,
       1.000000;-1.000000; 1.000000;,
       1.000000;-1.000000;-1.000000;,
       1.000000;-1.000000;-1.000000;,
       1.000000;-1.000000; 1.000000;,
      -1.000000;-1.000000; 1.000000;,
      -1.000000;-1.000000;-1.000000;,
      -1.000000; 1.000000;-1.000000;,
       1.000000; 1.000000;-1.000000;,
       1.000000;-1.000000;-1.000000;,
      -1.000000;-1.000000;-1.000000;,
       1.000000; 1.000000; 1.000000;,
      -1.000000; 1.000000; 1.000000;,
      -1.000000;-1.000000; 1.000000;,
       1.000000;-1.000000; 1.000000;;
      6;
      4;3,2,1,0;,
      4;7,6,5,4;,
      4;11,10,9,8;,
      4;15,14,13,12;,
      4;19,18,17,16;,
      4;23,22,21,20;;
      MeshNormals { // Wall1 normals
        6;
        -1.000000;-0.000000; 0.000000;,
         0.000000; 1.000000; 0.000000;,
         1.000000;-0.000000; 0.000000;,
         0.000000;-1.000000; 0.000000;,
         0.000000; 0.000000;-1.000000;,
         0.000000;-0.000000; 1.000000;;
        6;
        4;0,0,0,0;,
        4;1,1,1,1;,
        4;2,2,2,2;,
        4;3,3,3,3;,
        4;4,4,4,4;,
        4;5,5,5,5;;
      } // End of Wall1 normals
      MeshTextureCoords { // Wall1 UV coordinates
        24;
         0.749950; 0.749950;,
         0.749950; 0.781632;,
         0.999900; 0.781632;,
         0.999900; 0.749950;,
         0.000100; 0.749950;,
         0.000100; 0.781632;,
         0.250050; 0.781632;,
         0.250050; 0.749950;,
         0.250050; 0.749950;,
         0.250050; 0.781632;,
         0.500000; 0.781632;,
         0.500000; 0.749950;,
         0.500000; 0.749950;,
         0.500000; 0.781632;,
         0.749950; 0.781632;,
         0.749950; 0.749950;,
         0.250050; 0.499800;,
         0.000100; 0.499800;,
         0.000100; 0.749750;,
         0.250050; 0.749750;,
         0.500200; 0.499800;,
         0.250250; 0.499800;,
         0.250250; 0.749750;,
         0.500200; 0.749750;;
      } // End of Wall1 UV coordinates
      MeshMaterialList { // Wall1 material list
        1;
        6;
        0,
        0,
        0,
        0,
        0,
        0;
        Material Wall_2 {
           0.640000; 0.640000; 0.640000; 1.000000;;
           96.078431;
           0.500000; 0.500000; 0.500000;;
           0.000000; 0.000000; 0.000000;;
        }
      } // End of Wall1 material list
    } // End of Wall1 mesh
  } // End of Wall1
} // End of Root