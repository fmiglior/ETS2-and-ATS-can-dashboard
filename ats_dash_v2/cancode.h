struct can_frame canMsg1; //0x0F6
struct can_frame canMsg2; //0x036
struct can_frame canMsg3; //0x0B6
struct can_frame canMsg4; //0x128
struct can_frame canMsg5; //0x168
struct can_frame canMsg6; //0x161


void carregaCAN () {
  // can code 1 = ajusta luz painel temp e odometro
 
  canMsg1.can_id  = 0x0F6;
  canMsg1.can_dlc = 8;
  canMsg1.data[0] = 0x8E; //igniçao
  canMsg1.data[1] = 0x00; //temperatura agua
  canMsg1.data[2] = 0x00; //odometro 1
  canMsg1.data[3] = 0x00; //odometro 2
  canMsg1.data[4] = 0x00; //odometro 3
  canMsg1.data[5] = 0x10;
  canMsg1.data[6] = 0x63;
  canMsg1.data[7] = 0x20;

// can code 2 liga painel
  canMsg2.can_id  = 0x036;
  canMsg2.can_dlc = 8;
  canMsg2.data[0] = 0x00;
  canMsg2.data[1] = 0x00;
  canMsg2.data[2] = 0x00;
  canMsg2.data[3] = 0x25; //brilho painel
  canMsg2.data[4] = 0x01; //chave ligada
  canMsg2.data[5] = 0x00;
  canMsg2.data[6] = 0x00;
  canMsg2.data[7] = 0xA0;

// can code 3 envia rpm velocidade 
  canMsg3.can_id  = 0x0B6;
  canMsg3.can_dlc = 8;
  canMsg3.data[0] = 0x00; //rpm
  canMsg3.data[1] = 0x00; 
  canMsg3.data[2] = 0x00; //velocidade
  canMsg3.data[3] = 0x00;
  canMsg3.data[4] = 0x00;
  canMsg3.data[5] = 0x00;
  canMsg3.data[6] = 0x00;
  canMsg3.data[7] = 0xA0;

 // can code 4 luzes painel e marcha
  canMsg4.can_id  = 0x128;
  canMsg4.can_dlc = 8;
  canMsg4.data[0] = 0x00;
  canMsg4.data[1] = 0x00;
  canMsg4.data[2] = 0x00;
  canMsg4.data[3] = 0x00;
  canMsg4.data[4] = 0x00;//luzes 
  canMsg4.data[5] = 0x00; 
  canMsg4.data[6] = 0x00; //indicador marcha
  canMsg4.data[7] = 0x01; 
  
   // can code 5 luzes painel 2
  canMsg5.can_id  = 0x168;
  canMsg5.can_dlc = 8;
  canMsg5.data[0] = 0x00;
  canMsg5.data[1] = 0x00;
  canMsg5.data[2] = 0x00;
  canMsg5.data[3] = 0x00; //abs e esp
  canMsg5.data[4] = 0x00;
  canMsg5.data[5] = 0x00;
  canMsg5.data[6] = 0x00;
  canMsg5.data[7] = 0x00; 
   
    // Combustivel
  canMsg6.can_id  = 0x161;
  canMsg6.can_dlc = 7;
  canMsg6.data[0] = 0x00;
  canMsg6.data[1] = 0x00;
  canMsg6.data[2] = 0x00;
  canMsg6.data[3] = 0x00; //marcador combustivel
  canMsg6.data[4] = 0x00;
  canMsg6.data[5] = 0x00;
  canMsg6.data[6] = 0x00;
    
}
