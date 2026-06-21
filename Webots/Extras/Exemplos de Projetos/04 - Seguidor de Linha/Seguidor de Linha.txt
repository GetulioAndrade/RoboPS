#include <stdio.h>
#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/distance_sensor.h>
#define TIME_STEP 13


int main()
{

  wb_robot_init();
    
  
    WbDeviceTag roda_direita, roda_esquerda;
    roda_direita = wb_robot_get_device("roda_direita");
    roda_esquerda = wb_robot_get_device("roda_esquerda");


 
    WbDeviceTag seguidor_de_linha1, seguidor_de_linha2, seguidor_de_linha3, seguidor_de_linha4, seguidor_de_linha5;
    seguidor_de_linha1 = wb_robot_get_device("seguidor_de_linha1");
    seguidor_de_linha2 = wb_robot_get_device("seguidor_de_linha2");
    seguidor_de_linha3 = wb_robot_get_device("seguidor_de_linha3");
    seguidor_de_linha4 = wb_robot_get_device("seguidor_de_linha4");
    seguidor_de_linha5 = wb_robot_get_device("seguidor_de_linha5");
    
    wb_distance_sensor_enable(seguidor_de_linha1, TIME_STEP);
    wb_distance_sensor_enable(seguidor_de_linha2, TIME_STEP);
    wb_distance_sensor_enable(seguidor_de_linha3, TIME_STEP);
    wb_distance_sensor_enable(seguidor_de_linha4, TIME_STEP);
    wb_distance_sensor_enable(seguidor_de_linha5, TIME_STEP); 
  
    
  while (wb_robot_step(TIME_STEP) != -1)
  {
    double roda_direita_velocidade = 0.0;
    double roda_esquerda_velocidade = 0.0;
    double seguidor[5];
    double x[6];
    
    
    wb_motor_set_position(roda_direita, INFINITY);
    wb_motor_set_position(roda_esquerda, INFINITY);
    wb_motor_set_velocity(roda_direita, roda_direita_velocidade);
    wb_motor_set_velocity(roda_esquerda, roda_esquerda_velocidade);
    
    
    seguidor[0] = wb_distance_sensor_get_value(seguidor_de_linha1);
    seguidor[1] = wb_distance_sensor_get_value(seguidor_de_linha2);
    seguidor[2] = wb_distance_sensor_get_value(seguidor_de_linha3);
    seguidor[3] = wb_distance_sensor_get_value(seguidor_de_linha4);
    seguidor[4] = wb_distance_sensor_get_value(seguidor_de_linha5);
    
    int y = 129 , z = 127;
    x[1] = (seguidor[0] - z);
    x[2] = (seguidor[1] - y);
    x[3] = (seguidor[2] - y);
    x[4] = (seguidor[3] - y);
    x[5] = (seguidor[4] - z);
    
    
    printf("\nSeguidor 1:%f \n", x[1]);
    printf("Seguidor 2:%f \n", x[2]);
    printf("Seguidor 3:%f \n", x[3]);
    printf("Seguidor 4:%f \n", x[4]);
    printf("Seguidor 5:%f \n", x[5]);
    
     //virar para direita
    if((x[2] <= 12) && (x[4] >= 12)){
      printf("1....\n");
      roda_direita_velocidade = 4.0;
      roda_esquerda_velocidade = 8.0;
      wb_motor_set_velocity(roda_direita, roda_direita_velocidade);
      wb_motor_set_velocity(roda_esquerda, roda_esquerda_velocidade);
    
    //virar para esquerda
    }else if((x[2] >= 12) && (x[4] <= 12)){
      printf("....2\n"); 
      roda_direita_velocidade = 8.0;
      roda_esquerda_velocidade = 4.0;	
      wb_motor_set_velocity(roda_direita, roda_direita_velocidade);
      wb_motor_set_velocity(roda_esquerda, roda_esquerda_velocidade);
    
    //parar
    }else if(((x[2] <= -10) && (x[3] <= -10) && (x[4] <= -10)) || 
             ((x[2] >= 10) && (x[3] >= 10) && (x[4] >= 10))){
      printf("PARADO\n");
      roda_direita_velocidade = 0;
      roda_esquerda_velocidade = 0;
      wb_motor_set_velocity(roda_direita, roda_direita_velocidade);
      wb_motor_set_velocity(roda_esquerda, roda_esquerda_velocidade);
    
    //andar
    }else{
      printf("..0..\n");
      roda_direita_velocidade = 8.0;
      roda_esquerda_velocidade = 8.0;
      wb_motor_set_velocity(roda_direita, roda_direita_velocidade);
      wb_motor_set_velocity(roda_esquerda, roda_esquerda_velocidade);
    }
       
  };

    
    wb_robot_cleanup();

  return 0;
}

