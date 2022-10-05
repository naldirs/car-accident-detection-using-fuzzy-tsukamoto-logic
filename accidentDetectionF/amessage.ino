String storeStat[5];
int numStat = 0;
int checkStat = false;

void createmessage(){
  /*enable status to store*/
  if(fuzzyf >= 3){
    checkStat = true;
  }
  /*storing status*/
  if(checkStat == true){
    storeStat[numStat] = {fuzzyh};
    numStat++;
    /*making car status for message*/    
    if(storeStat[0] == "Terguling" || storeStat[1] == "Terguling" || storeStat[2] == "Terguling" || storeStat[3] == "Terguling" || storeStat[4] == "Terguling"){
      carStatus='t';
    }
    else{
      carStatus='k';
    }
  }
  /*check the store for message to send*/
  if(storeStat[0] != "" && storeStat[1] != "" && storeStat[2] != "" && storeStat[3] != "" && storeStat[4] != ""){
    /*sending message (t = tergulig)*/
    if(carStatus == 't'){
      terguling();
      sendCommands('t');
      storeEmpty();
    }
    /*sending message (k = tabrakan)*/ 
    else if (carStatus == 'k'){
      tabrakan();
      sendCommands('k');
      storeEmpty();
    }
  }
  /*set Status num to not more than 4 and disabling status to store*/
  if (numStat >=5) {
    numStat=0; 
    checkStat = false;
  }
  //printCM();
}


void storeEmpty(){
  storeStat[0] = "";
  storeStat[1] = "";
  storeStat[2] = "";
  storeStat[3] = "";
  storeStat[4] = "";
}

void printCM(){
  Serial.println(numStat);
  Serial.println("0. "+storeStat[0]);
  Serial.println("1. "+storeStat[1]);
  Serial.println("2. "+storeStat[2]);
  Serial.println("3. "+storeStat[3]);
  Serial.println("4. "+storeStat[4]);
}
