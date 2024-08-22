xof 0303txt 0032
template ColorRGBA {
 <35ff44e0-6c7c-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <d3e16e81-7835-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template Material {
 <3d82ab4d-62da-11cf-ab39-0020af71e433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template TextureFilename {
 <a42790e1-7810-11cf-8f52-0040333594a3>
 STRING filename;
}

template Frame {
 <3d82ab46-62da-11cf-ab39-0020af71e433>
 [...]
}

template Matrix4x4 {
 <f6f23f45-7686-11cf-8f52-0040333594a3>
 array FLOAT matrix[16];
}

template FrameTransformMatrix {
 <f6f23f41-7686-11cf-8f52-0040333594a3>
 Matrix4x4 frameMatrix;
}

template Vector {
 <3d82ab5e-62da-11cf-ab39-0020af71e433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template MeshFace {
 <3d82ab5f-62da-11cf-ab39-0020af71e433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template Mesh {
 <3d82ab44-62da-11cf-ab39-0020af71e433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

template MeshMaterialList {
 <f6f23f42-7686-11cf-8f52-0040333594a3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material <3d82ab4d-62da-11cf-ab39-0020af71e433>]
}

template VertexElement {
 <f752461c-1e23-48f6-b9f8-8350850f336f>
 DWORD Type;
 DWORD Method;
 DWORD Usage;
 DWORD UsageIndex;
}

template DeclData {
 <bf22e553-292c-4781-9fea-62bd554bdd93>
 DWORD nElements;
 array VertexElement Elements[nElements];
 DWORD nDWords;
 array DWORD data[nDWords];
}


Material Material__25 {
 1.000000;1.000000;1.000000;1.000000;;
 100.000000;
 0.200000;0.200000;0.200000;;
 0.000000;0.000000;0.000000;;

 TextureFilename {
  "D:\\Media\\cfcard.bmp";
 }
}

Frame CFCard {
 

 FrameTransformMatrix {
  23.395483,0.000000,0.000000,0.000000,0.000000,5.184654,0.000001,0.000000,0.000000,-0.000004,23.395483,0.000000,0.000000,0.000000,0.000000,1.000000;;
 }

 Mesh CFCard {
  88;
  -0.020000;0.020000;0.020000;,
  0.020000;0.020000;0.020000;,
  0.020000;0.020000;-0.020000;,
  0.020000;0.020000;-0.020000;,
  0.020000;0.010000;-0.020000;,
  -0.020000;0.010000;-0.020000;,
  -0.020000;0.020000;-0.020000;,
  -0.020000;0.010000;-0.020000;,
  -0.020000;0.010000;0.020000;,
  0.020000;-0.020000;0.020000;,
  -0.020000;-0.020000;0.020000;,
  -0.020000;-0.020000;-0.020000;,
  0.020000;0.020000;0.020000;,
  0.020000;0.010000;0.020000;,
  0.020000;0.010000;-0.020000;,
  -0.020000;0.020000;0.020000;,
  -0.020000;0.010000;0.020000;,
  0.020000;0.010000;0.020000;,
  -0.020000;-0.010000;-0.020000;,
  -0.020000;-0.010000;0.020000;,
  -0.016728;-0.008119;0.016728;,
  0.020000;0.010000;0.020000;,
  -0.020000;0.010000;0.020000;,
  -0.016728;0.008609;0.016728;,
  -0.020000;-0.010000;0.020000;,
  0.020000;-0.010000;0.020000;,
  0.016728;-0.008119;0.016728;,
  0.020000;-0.010000;-0.020000;,
  0.020000;-0.020000;-0.020000;,
  -0.020000;-0.020000;-0.020000;,
  -0.020000;-0.010000;-0.020000;,
  -0.020000;-0.020000;-0.020000;,
  -0.020000;-0.020000;0.020000;,
  0.020000;-0.010000;0.020000;,
  0.020000;-0.020000;0.020000;,
  0.020000;-0.020000;-0.020000;,
  -0.020000;-0.010000;0.020000;,
  -0.020000;-0.020000;0.020000;,
  0.020000;-0.020000;0.020000;,
  -0.020000;0.010000;0.020000;,
  -0.020000;0.010000;-0.020000;,
  -0.016728;0.008609;-0.016728;,
  0.016728;0.008609;0.016728;,
  0.016728;-0.008119;0.016728;,
  0.016728;-0.008119;-0.016728;,
  -0.016728;0.008609;-0.016728;,
  -0.016728;-0.008119;-0.016728;,
  -0.016728;-0.008119;0.016728;,
  0.016728;0.008609;-0.016728;,
  0.016728;-0.008119;-0.016728;,
  -0.016728;-0.008119;-0.016728;,
  -0.016728;0.008609;0.016728;,
  -0.016728;-0.008119;0.016728;,
  0.016728;-0.008119;0.016728;,
  -0.020000;0.010000;-0.020000;,
  0.020000;0.010000;-0.020000;,
  0.016728;0.008609;-0.016728;,
  0.020000;0.010000;-0.020000;,
  0.020000;0.010000;0.020000;,
  0.016728;0.008609;0.016728;,
  0.020000;-0.010000;0.020000;,
  0.020000;-0.010000;-0.020000;,
  0.016728;-0.008119;-0.016728;,
  0.020000;-0.010000;-0.020000;,
  -0.020000;-0.010000;-0.020000;,
  -0.016728;-0.008119;-0.016728;,
  -0.020000;0.020000;-0.020000;,
  -0.020000;0.020000;-0.020000;,
  -0.020000;0.020000;0.020000;,
  0.020000;-0.020000;-0.020000;,
  0.020000;0.020000;-0.020000;,
  0.020000;0.020000;0.020000;,
  -0.016728;-0.008119;-0.016728;,
  0.016728;0.008609;0.016728;,
  -0.016728;-0.008119;0.016728;,
  -0.020000;-0.010000;-0.020000;,
  -0.020000;-0.010000;0.020000;,
  0.020000;-0.010000;-0.020000;,
  0.020000;-0.010000;0.020000;,
  -0.016728;0.008609;0.016728;,
  0.016728;0.008609;-0.016728;,
  -0.016728;0.008609;0.016728;,
  -0.016728;0.008609;-0.016728;,
  0.016728;0.008609;0.016728;,
  -0.016728;0.008609;-0.016728;,
  0.016728;0.008609;-0.016728;,
  0.016728;-0.008119;0.016728;,
  0.016728;-0.008119;-0.016728;;
  44;
  3;0,1,2;,
  3;3,4,5;,
  3;6,7,8;,
  3;9,10,11;,
  3;12,13,14;,
  3;15,16,17;,
  3;18,19,20;,
  3;21,22,23;,
  3;24,25,26;,
  3;27,28,29;,
  3;30,31,32;,
  3;33,34,35;,
  3;36,37,38;,
  3;39,40,41;,
  3;42,43,44;,
  3;45,46,47;,
  3;48,49,50;,
  3;51,52,53;,
  3;54,55,56;,
  3;57,58,59;,
  3;60,61,62;,
  3;63,64,65;,
  3;0,2,66;,
  3;3,5,67;,
  3;6,8,68;,
  3;9,11,69;,
  3;12,14,70;,
  3;15,17,71;,
  3;18,20,72;,
  3;21,23,73;,
  3;24,26,74;,
  3;27,29,75;,
  3;30,32,76;,
  3;33,35,77;,
  3;36,38,78;,
  3;39,41,79;,
  3;42,44,80;,
  3;45,47,81;,
  3;48,50,82;,
  3;51,53,83;,
  3;54,56,84;,
  3;57,59,85;,
  3;60,62,86;,
  3;63,65,87;;

  MeshMaterialList {
   1;
   44;
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0;
   { Material__25 }
  }

  DeclData {
   4;
   2;0;3;0;,
   2;0;6;0;,
   2;0;7;0;,
   1;0;5;0;;
   968;
   0,
   1065353216,
   696254464,
   3212836864,
   0,
   0,
   0,
   2843738112,
   1065353216,
   1063256064,
   1056964608,
   0,
   1065353216,
   696254464,
   3212836864,
   0,
   0,
   0,
   2843738112,
   1065353216,
   1059061760,
   1056964608,
   0,
   1065353216,
   696254464,
   3212836864,
   0,
   0,
   0,
   2843738112,
   1065353216,
   1059061760,
   1048576000,
   0,
   0,
   3212836864,
   0,
   1065353216,
   0,
   1065353216,
   0,
   0,
   1059061760,
   1048576000,
   0,
   0,
   3212836864,
   0,
   1065353216,
   0,
   1065353216,
   0,
   0,
   1058013184,
   1048576000,
   0,
   0,
   3212836864,
   0,
   1065353216,
   0,
   1065353216,
   0,
   0,
   1058013184,
   0,
   3212836864,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   3212836864,
   1059061760,
   1065353216,
   3212836864,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   3212836864,
   1058013184,
   1065353216,
   3212836864,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   3212836864,
   1058013184,
   1061158912,
   0,
   3212836864,
   2843738112,
   1065353216,
   0,
   0,
   0,
   2843738112,
   1065353216,
   1052770304,
   1056964608,
   0,
   3212836864,
   2843738112,
   1065353216,
   0,
   0,
   0,
   2843738112,
   1065353216,
   1040187392,
   1056964608,
   0,
   3212836864,
   2843738112,
   1065353216,
   0,
   0,
   0,
   2843738112,
   1065353216,
   1040187392,
   1048576000,
   1065353216,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   1065353216,
   1059061760,
   1056964608,
   1065353216,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   1065353216,
   1058013184,
   1056964608,
   1065353216,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   1065353216,
   1058013184,
   1048576000,
   0,
   0,
   1065353216,
   0,
   1065353216,
   0,
   3212836864,
   0,
   0,
   1059061760,
   1061158912,
   0,
   0,
   1065353216,
   0,
   1065353216,
   0,
   3212836864,
   0,
   0,
   1058013184,
   1061158912,
   0,
   0,
   1065353216,
   0,
   1065353216,
   0,
   3212836864,
   0,
   0,
   1058013184,
   1056964608,
   3204392088,
   1063121673,
   694022921,
   685585617,
   2839571845,
   1065353216,
   1063121673,
   1056908440,
   0,
   1054867456,
   1065353216,
   3204392088,
   1063121673,
   694022921,
   685585617,
   2839571845,
   1065353216,
   1063121673,
   1056908440,
   0,
   1054867456,
   1061158912,
   3204392088,
   1063121673,
   694022921,
   685585617,
   2839571845,
   1065353216,
   1063121673,
   1056908440,
   0,
   1054867456,
   1061158912,
   0,
   3211499001,
   1053317716,
   0,
   1053317716,
   1064015353,
   3212836864,
   0,
   0,
   1058013184,
   1056964608,
   0,
   3211499001,
   1053317716,
   0,
   1053317716,
   1064015353,
   3212836864,
   0,
   0,
   1058013184,
   1061158912,
   0,
   3211499001,
   1053317716,
   0,
   1053317716,
   1064015353,
   3212836864,
   0,
   0,
   1058013184,
   1061158912,
   0,
   1063121675,
   1056908433,
   0,
   3204392081,
   1063121675,
   1065353216,
   0,
   2147483648,
   1054867456,
   1061158912,
   0,
   1063121675,
   1056908433,
   0,
   3204392081,
   1063121675,
   1065353216,
   0,
   2147483648,
   1054867456,
   1056964608,
   0,
   1063121675,
   1056908433,
   0,
   3204392081,
   1063121675,
   1065353216,
   0,
   2147483648,
   1054867456,
   1056964608,
   0,
   0,
   3212836864,
   0,
   1065353216,
   0,
   1065353216,
   0,
   0,
   1054867456,
   1048576000,
   0,
   0,
   3212836864,
   0,
   1065353216,
   0,
   1065353216,
   0,
   0,
   1052770304,
   1048576000,
   0,
   0,
   3212836864,
   0,
   1065353216,
   0,
   1065353216,
   0,
   0,
   1052770304,
   0,
   3212836864,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   3212836864,
   1054867456,
   1065353216,
   3212836864,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   3212836864,
   1052770304,
   1065353216,
   3212836864,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   3212836864,
   1052770304,
   1061158912,
   1065353216,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   1065353216,
   1054867456,
   1056964608,
   1065353216,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   1065353216,
   1052770304,
   1056964608,
   1065353216,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   1065353216,
   1052770304,
   1048576000,
   0,
   0,
   1065353216,
   0,
   1065353216,
   0,
   3212836864,
   0,
   0,
   1054867456,
   1061158912,
   0,
   0,
   1065353216,
   0,
   1065353216,
   0,
   3212836864,
   0,
   0,
   1052770304,
   1061158912,
   0,
   0,
   1065353216,
   0,
   1065353216,
   0,
   3212836864,
   0,
   0,
   1052770304,
   1056964608,
   3200801364,
   3211499001,
   2842400249,
   2830655563,
   2841169071,
   1065353216,
   3211499001,
   1053317716,
   0,
   1058013184,
   1061158912,
   3200801364,
   3211499001,
   2842400249,
   2830655563,
   2841169071,
   1065353216,
   3211499001,
   1053317716,
   0,
   1058013184,
   1065353216,
   3200801364,
   3211499001,
   2842400249,
   2830655563,
   2841169071,
   1065353216,
   3211499001,
   1053317716,
   0,
   1058013184,
   1065353216,
   1065353216,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   1065353216,
   1058013184,
   1056964608,
   1065353216,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   1065353216,
   1054867456,
   1056964608,
   1065353216,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   1065353216,
   1054867456,
   1048576000,
   3212836864,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   3212836864,
   1058013184,
   1065353216,
   3212836864,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   3212836864,
   1054867456,
   1065353216,
   3212836864,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   3212836864,
   1054867456,
   1061158912,
   0,
   0,
   3212836864,
   0,
   1065353216,
   0,
   1065353216,
   0,
   0,
   1058013184,
   1048576000,
   0,
   0,
   3212836864,
   0,
   1065353216,
   0,
   1065353216,
   0,
   0,
   1054867456,
   1048576000,
   0,
   0,
   3212836864,
   0,
   1065353216,
   0,
   1065353216,
   0,
   0,
   1054867456,
   0,
   0,
   0,
   1065353216,
   0,
   1065353216,
   0,
   3212836864,
   0,
   0,
   1058013184,
   1061158912,
   0,
   0,
   1065353216,
   0,
   1065353216,
   0,
   3212836864,
   0,
   0,
   1054867456,
   1061158912,
   0,
   0,
   1065353216,
   0,
   1065353216,
   0,
   3212836864,
   0,
   0,
   1054867456,
   1056964608,
   0,
   3211499001,
   3200801364,
   0,
   3200801364,
   1064015353,
   3212836864,
   2147483648,
   0,
   1058013184,
   0,
   0,
   3211499001,
   3200801364,
   0,
   3200801364,
   1064015353,
   3212836864,
   2147483648,
   0,
   1058013184,
   1048576000,
   0,
   3211499001,
   3200801364,
   0,
   3200801364,
   1064015353,
   3212836864,
   2147483648,
   0,
   1058013184,
   1048576000,
   1053317716,
   3211499001,
   2842400249,
   683171915,
   2841169071,
   1065353216,
   3211499001,
   3200801364,
   0,
   1058013184,
   1048576000,
   1053317716,
   3211499001,
   2842400249,
   683171915,
   2841169071,
   1065353216,
   3211499001,
   3200801364,
   0,
   1058013184,
   1056964608,
   1053317716,
   3211499001,
   2842400249,
   683171915,
   2841169071,
   1065353216,
   3211499001,
   3200801364,
   0,
   1058013184,
   1056964608,
   1056908440,
   1063121673,
   694022921,
   2833069265,
   2839571845,
   1065353216,
   1063121673,
   3204392088,
   0,
   1054867456,
   1056964608,
   1056908440,
   1063121673,
   694022921,
   2833069265,
   2839571845,
   1065353216,
   1063121673,
   3204392088,
   0,
   1054867456,
   1048576000,
   1056908440,
   1063121673,
   694022921,
   2833069265,
   2839571845,
   1065353216,
   1063121673,
   3204392088,
   0,
   1054867456,
   1048576000,
   0,
   1063121675,
   3204392081,
   0,
   1056908433,
   1063121675,
   1065353216,
   2147483648,
   0,
   1054867456,
   1048576000,
   0,
   1063121675,
   3204392081,
   0,
   1056908433,
   1063121675,
   1065353216,
   2147483648,
   0,
   1054867456,
   0,
   0,
   1063121675,
   3204392081,
   0,
   1056908433,
   1063121675,
   1065353216,
   2147483648,
   0,
   1054867456,
   0,
   0,
   1065353216,
   696254464,
   3212836864,
   0,
   0,
   0,
   2843738112,
   1065353216,
   1063256064,
   1048576000,
   0,
   0,
   3212836864,
   0,
   1065353216,
   0,
   1065353216,
   0,
   0,
   1059061760,
   0,
   3212836864,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   3212836864,
   1059061760,
   1061158912,
   0,
   3212836864,
   2843738112,
   1065353216,
   0,
   0,
   0,
   2843738112,
   1065353216,
   1052770304,
   1048576000,
   1065353216,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   1065353216,
   1059061760,
   1048576000,
   0,
   0,
   1065353216,
   0,
   1065353216,
   0,
   3212836864,
   0,
   0,
   1059061760,
   1056964608,
   3204392074,
   1063121677,
   694022925,
   685585609,
   2839571852,
   1065353216,
   1063121677,
   1056908426,
   0,
   1054867456,
   1065353216,
   0,
   3211499001,
   1053317714,
   0,
   1053317715,
   1064015353,
   3212836864,
   0,
   0,
   1058013184,
   1056964608,
   0,
   1063121675,
   1056908434,
   0,
   3204392082,
   1063121675,
   1065353216,
   0,
   2147483648,
   1054867456,
   1061158912,
   0,
   0,
   3212836864,
   0,
   1065353216,
   0,
   1065353216,
   0,
   0,
   1054867456,
   0,
   3212836864,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   3212836864,
   1054867456,
   1061158912,
   1065353216,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   1065353216,
   1054867456,
   1048576000,
   0,
   0,
   1065353216,
   0,
   1065353216,
   0,
   3212836864,
   0,
   0,
   1054867456,
   1056964608,
   3200801370,
   3211499000,
   2842400248,
   2830655567,
   2841169069,
   1065353216,
   3211499000,
   1053317722,
   0,
   1058013184,
   1061158912,
   1065353216,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   1065353216,
   1058013184,
   1048576000,
   3212836864,
   0,
   0,
   0,
   1065353216,
   0,
   0,
   0,
   3212836864,
   1058013184,
   1061158912,
   0,
   0,
   3212836864,
   0,
   1065353216,
   0,
   1065353216,
   0,
   0,
   1058013184,
   0,
   0,
   0,
   1065353216,
   0,
   1065353216,
   0,
   3212836864,
   0,
   0,
   1058013184,
   1056964608,
   0,
   3211499001,
   3200801362,
   0,
   3200801363,
   1064015353,
   3212836864,
   2147483648,
   0,
   1058013184,
   0,
   1053317722,
   3211499000,
   2842400248,
   683171919,
   2841169069,
   1065353216,
   3211499000,
   3200801370,
   0,
   1058013184,
   1048576000,
   1056908426,
   1063121677,
   694022925,
   2833069257,
   2839571852,
   1065353216,
   1063121677,
   3204392074,
   0,
   1054867456,
   1056964608,
   0,
   1063121675,
   3204392082,
   0,
   1056908434,
   1063121675,
   1065353216,
   2147483648,
   0,
   1054867456,
   1048576000;
  }
 }
}