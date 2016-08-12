/*
 * File:   Semáforo
 * Author: Ickson Barbosa
 *
 * Created on 12 de Agosto de 2016, 11:35
 */

#define _XTAL_FREQ 16000000

#define VERMELHO 1
#define AMARELO 2
#define VERDE 3

#include <xc.h>
 
// BEGIN CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital input, MCLR internally tied to VDD)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
//END CONFIG
char estado = 0;

void executaEstados(int porta, int tempo)
{
   PORTB = porta;  //Led Vermelho Ligado
    __delay_ms(tempo); //Delay 5 segundos  
}

void configuraEstados()
{
    switch (estado)
    {
        case 1:
                executaEstados(0b00001000, 5000);  //Led Vermelho Ligado, Delay 5 segundos
                estado = AMARELO;
                break;
        case 2:
                executaEstados(0b00010000, 2000); //Led Amarelo Ligado, Delay 2 segundos
                estado = VERDE;
                break;
        case 3:
                executaEstados(0b00100000, 5000); //Led Verde Ligado, Delay 5 segundos
                estado = VERMELHO;
                break;
        
    }
}

int main()
{
  TRISB  = 0; //RA0 como saida
  estado = VERMELHO;
  while(1)
  {
      configuraEstados();
  }
  return 0;
}
