/* Nilai fungsi input */
float xTinggin[2] = {-4,0}; float xRendah[3] = {-4,0,4}; float xTinggip[2] = {0,4};
float ySangatTinggin[2] = {-8,-4}; float yTinggin[3] = {-8,-4,0}; float yRendah[3] = {-4,0,4}; float yTinggip[3] = {0,4,8}; float ySangatTinggip[2] = {4,8};
float gRendah[2] = {0,5000}; float gTinggi[2] = {0,5000};
/* Nilai fungsi output */
float sNormal[2] = {0,3};  float sTabrakan[3] = {3,4.5,6};   float sTerguling[2] = {6,9};

// Fuzzyfikasi
float kurvaTurun(float input, float batasA, float batasB){
  float hasil;
  //batas b[0] = a, b[1] = b
  float b[2] = {batasA, batasB};
  if(input <= b[0]) hasil=1; 
  else if (input >= b[0] && input <= b[1]) hasil=(b[1]-input)/(b[1]-b[0]);
  else if (input >= b[1]) hasil=0;
  return hasil;
}
float kurvaSegitiga(float input, float batasA, float batasB, float batasC){
  float hasil;
  //batas b[0]=a, b[1]=b, b[1]=c
  float b[3] = {batasA, batasB, batasC};
  if(input <= b[0]) hasil=0; 
  else if (input >= b[0] && input <=b[1]) hasil=(input-b[0])/(b[1]-b[0]);
  else if (input >= b[1] && input <=b[2]) hasil=(b[2]-input)/(b[2]-b[1]);
  else if (input >= b[2]) hasil=0;
  return hasil;
}
float kurvaNaik(float input, float batasA, float batasB){
  float hasil;
  //batas b[0] = a, b[1] = b
  float b[2] = {batasA, batasB};
  if(input <= b[0]) hasil=0; 
  else if (input >= b[0] && input <= b[1]) hasil=(input-b[0])/(b[1]-b[0]);
  else if (input >= b[1]) hasil=1;
  return hasil;
}

// menghitung nilai z dari ke 3 output
float Normal(float z){
  float hitung;
  hitung=sNormal[1]-(z*(sNormal[1]-sNormal[0]));
  return hitung;
}
float Tabrakan(float z){
  float hitung,t1,t2;
  t1=sTabrakan[0]+(z*(sTabrakan[1]-sTabrakan[0]));
  t2=sTabrakan[2]-(z*(sTabrakan[2]-sTabrakan[1]));
  hitung = min(t1,t2);
  return hitung;
}
float Terguling(float z){
  float hitunng;
  hitunng=sTerguling[0]+(z*(sTerguling[1]-sTerguling[0]));
  return hitunng;
}

float fuzzy(float x, float y, float g){
  // tahap fuzzyfikasi
  float xtinggin, xrendah, xtinggip, 
        ysangattinggin, ytinggin, yrendah, ytinggip, ysangattinggip, 
        grendah, gtinggi;
  
  xtinggin=kurvaTurun(x, xTinggin[0], xTinggin[1]); 
  xrendah=kurvaSegitiga(x, xRendah[0], xRendah[1], xRendah[2]); 
  xtinggip=kurvaNaik(x, xTinggip[0], xTinggip[1]);

  ysangattinggin=kurvaTurun(y, ySangatTinggin[0], ySangatTinggin[1]); 
  ytinggin=kurvaSegitiga(y, yTinggin[0], yTinggin[1], yTinggin[2]); 
  yrendah=kurvaSegitiga(y, yRendah[0], yRendah[1], yRendah[2]); 
  ytinggip=kurvaSegitiga(y, yTinggip[0], yTinggip[1], yTinggip[2]); 
  ysangattinggip=kurvaNaik(y, ySangatTinggip[0], ySangatTinggip[1]);

  grendah = kurvaTurun(g, gRendah[0], gRendah[1]); 
  gtinggi = kurvaNaik(g, gTinggi[0], gTinggi[1]);


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
