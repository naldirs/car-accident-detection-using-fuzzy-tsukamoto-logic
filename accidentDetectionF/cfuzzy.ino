// Fuzzyfikasi
// himpunan akselerometer(X)
float xTinggin(float aksx){
  float xtinggin;
  //batas b[0] = a, b[1] = b
  float b[2] = {-4,0};
  if(aksx <= b[0]) xtinggin=1; 
  else if (aksx >= b[0] && aksx <= b[1]) xtinggin=(b[1]-aksx)/(b[1]-b[0]);
  else if (aksx >= b[1]) xtinggin=0;
  return xtinggin;
}
float xRendah(float aksx){
  float xrendah;
  //batas b[0]=a, b[1]=b, b[1]=c
  float b[3] = {-4,0,4};
  if(aksx <= b[0]) xrendah=0; 
  else if (aksx >= b[0] && aksx <=b[1]) xrendah=(aksx-b[0])/(b[1]-b[0]);
  else if (aksx >= b[1] && aksx <=b[2]) xrendah=(b[2]-aksx)/(b[2]-b[1]);
  else if (aksx >= b[2]) xrendah=0;
  return xrendah;
}
float xTinggip(float aksx){
  float xtinggip;
  //batas b[0] = a, b[1] = b
  float b[2] = {0,4};
  if(aksx <= b[0]) xtinggip=0; 
  else if (aksx >= b[0] && aksx <= b[1]) xtinggip=(aksx-b[0])/(b[1]-b[0]);
  else if (aksx >= b[1]) xtinggip=1;
  return xtinggip;
}
// himpunan akselerometer(Y)
float ySangatTinggin(float aksy){
  float ysangattinggin;
  //batas b[0] = a, b[1] = b
  float b[2] = {-8,-4};
  if(aksy <= b[0]) ysangattinggin=1; 
  else if (aksy >= b[0] && aksy <=b[1]) ysangattinggin=(b[1]-aksy)/(b[1]-b[0]);
  else if (aksy >= b[1]) ysangattinggin=0;
  return ysangattinggin;
}
float yTinggin(float aksy){
  float ytinggin;
  //batas b[0]=a, b[1]=b, b[1]=c
  float b[3] = {-8,-4,0};
  if(aksy <= b[0]) ytinggin=0; 
  else if (aksy >= b[0] && aksy <= b[1]) ytinggin=(aksy-b[0])/(b[1]-b[0]);
  else if (aksy >= b[1] && aksy <= b[2]) ytinggin=(b[2]-aksy)/(b[2]-b[1]);
  else if (aksy >= b[2]) ytinggin=0;
  return ytinggin;
}
float yRendah(float aksy){
  float yrendah;
  //batas b[0]=a, b[1]=b, b[1]=c
  float b[3] = {-4,0,4};
  if(aksy <= b[0]) yrendah=0; 
  else if (aksy >= b[0] && aksy <= b[1]) yrendah=(aksy-b[0])/(b[1]-b[0]);
  else if (aksy >= b[1] && aksy <= b[2]) yrendah=(b[2]-aksy)/(b[2]-b[1]);
  else if (aksy >= b[2]) yrendah=0;
  return yrendah;
}
float yTinggip(float aksy){
  float ytinggip;
  //batas b[0]=a, b[1]=b, b[1]=c
  float b[3] = {0,4,8};
  if(aksy <= b[0]) ytinggip=0; 
  else if (aksy >= b[0] && aksy <= b[1]) ytinggip=(aksy-b[0])/(b[1]-b[0]);
  else if (aksy >= b[1] && aksy <= b[2]) ytinggip=(b[2]-aksy)/(b[2]-b[1]);
  else if (aksy >= b[2]) ytinggip=0;
  return ytinggip;
}
float ySangatTinggip(float aksy){
  float ysangattinggip;
  //batas b[0] = a, b[1] = b
  float b[2] = {4,8};
  if(aksy <= b[0]) ysangattinggip = 0; 
  else if (aksy >= b[0] && aksy <= b[1]) ysangattinggip=(aksy-b[0])/(b[1]-b[0]);
  else if (aksy >= b[1]) ysangattinggip=1;
  return ysangattinggip;
}
//himpunan getaran
float gRendah(float getr){
  float grendah;
  //batas b[0] = a, b[1] = b
  float b[2] = {0,5000};
  if(getr <= b[0]) grendah=1; 
  else if (getr >= b[0] && getr <= b[1]) grendah=(b[1]-getr)/(b[1]-b[0]);
  else if (getr >= b[1]) grendah=0;
  return grendah;
}
float gTinggi(float getr){
  float gtinggi;
  //batas b[0] = a, b[1] = b
  float b[2] = {0,5000};
  if(getr <= b[0]) gtinggi=0; 
  else if (getr >= b[0] && getr <= b[1]) gtinggi=(getr-b[0])/(b[1]-b[0]);
  else if (getr >= b[1]) gtinggi=1;
  return gtinggi;
}

// menghitung nilai z dari ke 3 output
float Normal(float z){
  float normal;
  float b[2] = {0,3};
  normal=b[1]-(z*(b[1]-b[0]));
  return normal;
}
float Tabrakan(float z){
  float tabrakan,t1,t2;
  float b[3] = {3,4.5,6};
  t1=b[0]+(z*(b[1]-b[0]));
  t2=b[2]-(z*(b[2]-b[1]));
  tabrakan = min(t1,t2);
  return tabrakan;
}
float Terguling(float z){
  float terguling;
  float b[2] = {6,9};
  terguling=b[0]+(z*(b[1]-b[0]));
  return terguling;
}

float fuzzy(float x, float y, float g){
  // tahap fuzzyfikasi
  float xtinggin, xrendah, xtinggip, ysangattinggin, ytinggin, yrendah, ytinggip, ysangattinggip, grendah, gtinggi; 
  xtinggin=xTinggin(x); xrendah=xRendah(x); xtinggip=xTinggip(x);
  ysangattinggin=ySangatTinggin(y); ytinggin=yTinggin(y); yrendah=yRendah(y); ytinggip=yTinggip(y); ysangattinggip=ySangatTinggip(y);
  grendah = gRendah(g); gtinggi = gTinggi(g);

  // inferensi
  // mencari nilai minimum a-predikat dan menghitung nilai z;
  float ap[30], z[30];
  ap[0]=min( min(xtinggin, ysangattinggin), gtinggi); z[0]=Terguling(ap[0]); 
  ap[1]=min( min(xtinggin, ysangattinggin), grendah); z[1]=Normal(ap[1]); 
  ap[2]=min( min(xtinggin, ytinggin), gtinggi); z[2]=Tabrakan(ap[2]);
  ap[3]=min( min(xtinggin, ytinggin), grendah); z[3]=Normal(ap[3]);
  ap[4]=min( min(xtinggin, yrendah), gtinggi); z[4]=Tabrakan(ap[4]);
  ap[5]=min( min(xtinggin, yrendah), grendah); z[5]=Normal(ap[5]);
  ap[6]=min( min(xtinggin, ytinggip), gtinggi); z[6]=Tabrakan(ap[6]);
  ap[7]=min( min(xtinggin, ytinggip), grendah); z[7]=Normal(ap[7]);
  ap[8]=min( min(xtinggin, ysangattinggip), gtinggi); z[8]=Terguling(ap[8]);
  ap[9]=min( min(xtinggin, ysangattinggip), grendah); z[9]=Normal(ap[9]);

  ap[10]=min( min(xrendah, ysangattinggin), gtinggi); z[10]=Terguling(ap[10]); 
  ap[11]=min( min(xrendah, ysangattinggin), grendah); z[11]=Normal(ap[11]); 
  ap[12]=min( min(xrendah, ytinggin), gtinggi); z[12]=Tabrakan(ap[12]);
  ap[13]=min( min(xrendah, ytinggin), grendah); z[13]=Normal(ap[13]);
  ap[14]=min( min(xrendah, yrendah), gtinggi); z[14]=Normal(ap[14]);
  ap[15]=min( min(xrendah, yrendah), grendah); z[15]=Normal(ap[15]);
  ap[16]=min( min(xrendah, ytinggip), gtinggi); z[16]=Tabrakan(ap[16]);
  ap[17]=min( min(xrendah, ytinggip), grendah); z[17]=Normal(ap[17]);
  ap[18]=min( min(xrendah, ysangattinggip), gtinggi); z[18]=Terguling(ap[18]);
  ap[19]=min( min(xrendah, ysangattinggip), grendah); z[19]=Normal(ap[19]);

  ap[20]=min( min(xtinggip, ysangattinggin), gtinggi); z[20]=Terguling(ap[20]); 
  ap[21]=min( min(xtinggip, ysangattinggin), grendah); z[21]=Normal(ap[21]); 
  ap[22]=min( min(xtinggip, ytinggin), gtinggi); z[22]=Tabrakan(ap[22]);
  ap[23]=min( min(xtinggip, ytinggin), grendah); z[23]=Normal(ap[23]);
  ap[24]=min( min(xtinggip, yrendah), gtinggi); z[24]=Tabrakan(ap[24]);
  ap[25]=min( min(xtinggip, yrendah), grendah); z[25]=Normal(ap[25]);
  ap[26]=min( min(xtinggip, ytinggip), gtinggi); z[26]=Tabrakan(ap[26]);
  ap[27]=min( min(xtinggip, ytinggip), grendah); z[27]=Normal(ap[27]);
  ap[28]=min( min(xtinggip, ysangattinggip), gtinggi); z[28]=Terguling(ap[28]);
  ap[29]=min( min(xtinggip, ysangattinggip), grendah); z[29]=Normal(ap[29]);

  //deffuzyfikasi
  //deklarasi variabel output
  float stat, apz, zt;
  apz = (ap[0]*z[0])+(ap[1]*z[1])+(ap[2]*z[2])+(ap[3]*z[3])+(ap[4]*z[4])+(ap[5]*z[5])+(ap[6]*z[6])+(ap[7]*z[7])+(ap[8]*z[8])+(ap[9]*z[9])+(ap[10]*z[10])+(ap[11]*z[11])+(ap[12]*z[12])+(ap[13]*z[13])+(ap[14]*z[14])+(ap[15]*z[15])+(ap[16]*z[16])+(ap[17]*z[17])+(ap[18]*z[18])+(ap[19]*z[19])+(ap[20]*z[20])+(ap[21]*z[21])+(ap[22]*z[22])+(ap[23]*z[23])+(ap[24]*z[24])+(ap[25]*z[25])+(ap[26]*z[26])+(ap[27]*z[27])+(ap[28]*z[28])+(ap[29]*z[29]);
  zt = (ap[0]+ap[1]+ap[2]+ap[3]+ap[4]+ap[5]+ap[6]+ap[7]+ap[8]+ap[9]+ap[10]+ap[11]+ap[12]+ap[13]+ap[14]+ap[15]+ap[16]+ap[17]+ap[18]+ap[19]+ap[20]+ap[21]+ap[22]+ap[23]+ap[24]+ap[25]+ap[26]+ap[27]+ap[28]+ap[29]);
  stat = apz/zt;

  return stat;
}

String himpunan(float x, float y, float g){
  String himpunan; 
  float z = fuzzy(x,y,g);
  if(z<=3){
    himpunan = "Normal";
  } 
  else if(z<=6) {
    himpunan = "Tabrakan";
  }
  else if(z<=9) {
    himpunan = "Terguling";
  }
  return himpunan;
}
