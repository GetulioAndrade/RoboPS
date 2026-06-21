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
    
    
    wb_motor_set_position(roda_direita, INFINITY);
    wb_motor_set_position(roda_esquerda, INFINITY);
    wb_motor_set_velocity(roda_direita, roda_direita_velocidade);
    wb_motor_set_velocity(roda_esquerda, roda_esquerda_velocidade);
    
    
    seguidor[0] = wb_distance_sensor_get_value(seguidor_de_linha1);
    seguidor[1] = wb_distance_sensor_get_value(seguidor_de_linha2);
    seguidor[2] = wb_distance_sensor_get_value(seguidor_de_linha3);
    seguidor[3] = wb_distance_sensor_get_value(seguidor_de_linha4);
    seguidor[4] = wb_distance_sensor_get_value(seguidor_de_linha5);
    
    printf("\nSeguidor 1:%f \n", seguidor[0]);
    printf("\nSeguidor 2:%f \n", seguidor[1]);
    printf("\nSeguidor 3:%f \n", seguidor[2]);
    printf("\nSeguidor 4:%f \n", seguidor[3]);
    printf("\nSeguidor 5:%f \n", seguidor[4]);
    
    wb_robot_cleanup();

  return 0;
}
}
