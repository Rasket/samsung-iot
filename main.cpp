/* WiFi Example
 * Copyright (c) 2016 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "PinNames.h"
#include "TCPSocket.h"
#include "Thread.h"
#include "mbed.h"
#include <cstdint>
#include <stdio.h>	//printf
#include <string.h>	//strlen
#include <string>
#include <sys/socket.h>	//socket
#include <arpa/inet.h>	//inet_addr
#include <vector>
#include "DigitalOut.h"
#include "hcsr04.h"
#include "mbed_wait_api.h"
#include "http_request.h"
#include "MFRC522.h"
#include "Dht11.h"
#include <cstdio>
#include "string"
#include "SPI.h"

WiFiInterface *wifi;
Serial pc(SERIAL_TX, SERIAL_RX);
DigitalOut myled(LED1);
HCSR04 sensor(D9, D10); 

MFRC522    RfChip   (PC_3, PC_2, PB_13, D14, D15);
Dht11 cala(A0);
SPI spi(D11, D12, D13);
DigitalOut cs(D7);
DigitalOut cs2(A1);
SPI spi2(PC_12, PC_11, PC_10);

void show_temp(string val)
{
    cs = 1;
    cs = 0;
    spi.format(8);
    spi.frequency(1000000);
    /*while (val.size() < 4) {
    temp.insert()
    }*/
    spi.write(129);
    spi.write(129);
    spi.write(129);
    spi.write(129);
 
    for (int i = 0; i < val.length(); i++) {
 

    switch (val[i]) {
    case '0':{
        spi.write(129);
        break;
    }
    case '1':{
        spi.write(243);
        break;
    }
    case '2':{
        spi.write(73);
        break;
    }
    case '3':{
        spi.write(97);
        break;
    }
    case '4':{
        spi.write(51);
        break;
    }
    case '5':{
        spi.write(37);
        break;
    }
    case '6':{
        spi.write(5);
        break;
    }
    case '7':{
        spi.write(241);
        break;
    }
    case '8':{
        spi.write(1);
        break;
    }
    case '9':{
        spi.write(33);
        break;
    }

    }
    }    
    spi.write(57);
    spi.write(141);
    cs = 1;
}

void show_helt(string val)
{
    cs2 = 1;
    cs2 = 0;
    spi2.format(8);
    spi2.frequency(1000000);
    /*while (val.size() < 4) {
    temp.insert()
    }*/
    spi2.write(129);
    spi2.write(129);
    spi2.write(129);
    spi2.write(129);
 
    for (int i = 0; i < val.length(); i++) {
 

    switch (val[i]) {
    case '0':{
        spi2.write(129);
        break;
    }
    case '1':{
        spi2.write(243);
        break;
    }
    case '2':{
        spi2.write(73);
        break;
    }
    case '3':{
        spi2.write(97);
        break;
    }
    case '4':{
        spi2.write(51);
        break;
    }
    case '5':{
        spi2.write(37);
        break;
    }
    case '6':{
        spi2.write(5);
        break;
    }
    case '7':{
        spi2.write(241);
        break;
    }
    case '8':{
        spi2.write(1);
        break;
    }
    case '9':{
        spi2.write(33);
        break;
    }

    }
    }    
    spi2.write(57);
    spi2.write(71);
    cs2 = 1;
}

void calla(string val)
{    
    cs = 1;
    cs = 0;
    string stro = "";
    /*while (val.size() < 4) {
    temp.insert()
    }*/
    while (val.size() > 0) {
        stro += val.back();
        val.pop_back();
    }
	while (stro.length() != 4)
	{
		stro += '0';
	}
 
    for (int i = 4; i > -1; i--) {
 
    spi.format(8);
    spi.frequency(1000000);
    switch (stro[i]) {
    case '0':{
        spi.write(129);
        break;
    }
    case '1':{
        spi.write(243);
        break;
    }
    case '2':{
        spi.write(73);
        break;
    }
    case '3':{
        spi.write(97);
        break;
    }
    case '4':{
        spi.write(51);
        break;
    }
    case '5':{
        spi.write(37);
        break;
    }
    case '6':{
        spi.write(5);
        break;
    }
    case '7':{
        spi.write(241);
        break;
    }
    case '8':{
        spi.write(1);
        break;
    }
    case '9':{
        spi.write(33);
        break;
    }
    }
    }    
    cs = 1;
}
void calla_alt(string val)
{    
    cs2 = 1;
    cs2 = 0;
    string stro = "";
    /*while (val.size() < 4) {
    temp.insert()
    }*/
    while (val.size() > 0) {
        stro += val.back();
        val.pop_back();
    }
	while (stro.length() != 4)
	{
		stro += '0';
	}
 
    for (int i = 4; i > -1; i--) {
 
    spi2.format(8);
    spi2.frequency(1000000);
    switch (stro[i]) {
    case '0':{
        spi2.write(129);
        break;
    }
    case '1':{
        spi2.write(243);
        break;
    }
    case '2':{
        spi2.write(73);
        break;
    }
    case '3':{
        spi2.write(97);
        break;
    }
    case '4':{
        spi2.write(51);
        break;
    }
    case '5':{
        spi2.write(37);
        break;
    }
    case '6':{
        spi2.write(5);
        break;
    }
    case '7':{
        spi2.write(241);
        break;
    }
    case '8':{
        spi2.write(1);
        break;
    }
    case '9':{
        spi2.write(33);
        break;
    }
    }
    }    
    cs2 = 1;
}


Thread thread;

int consta = 1;
int value = 0;
int tima;


void show_time()
{
    tima = 0;
    while (1) {
    printf("%i ", tima);
    if (consta)
    {
        wait_us(1000000);
        tima++;
    }
    else {
    return ;
    }
    }


}


string dump_response(HttpResponse* res) {
    printf("Status: %d - %s\n", res->get_status_code(), res->get_status_message().c_str());
 
    printf("Headers:\n");
    for (size_t ix = 0; ix < res->get_headers_length(); ix++) {
        printf("\t%s: %s\n", res->get_headers_fields()[ix]->c_str(), res->get_headers_values()[ix]->c_str());
    }
    printf("\nBody (%d bytes):\n\n%s\n", res->get_body_length(), res->get_body_as_string().c_str());
    std::string temp = res->get_body_as_string().c_str();
    return temp;
}
 

int remaining;
int rcount;
char *p;
char *buffer = new char[256];

 
 void sendData(vector<string> data, TCPSocket* socketa)
 {
        HttpRequest* get_req = new HttpRequest(socketa, HTTP_POST, "http://192.168.1.72/check/");
 
        get_req->set_header("Content-Type", "application/json");
        string body = "{\"" + data[0] + "\":\"" +data[1] + "\"}";

        HttpResponse* post_res = get_req->send(body.c_str(), body.length());
        if (!post_res) {
            printf("HttpRequest failed (error code %d)\n", get_req->get_error());
        }
 
        printf("\n----- HTTP POST response -----\n");
        string dataRet = dump_response(post_res);
 
        delete get_req;
 }
 
int getTrain(vector<string> data, TCPSocket* socketa)
{
        HttpRequest* get_req = new HttpRequest(socketa, HTTP_POST, "http://192.168.1.72/getTrain/");
 
        get_req->set_header("Content-Type", "application/json");
 
        string body = "{\"" + data[0] + "\":\"" +data[1] + "\"}";
 
        HttpResponse* post_res = get_req->send(body.c_str(), body.length());
        if (!post_res) {
            printf("HttpRequest failed (error code %d)\n", get_req->get_error());
        }
 
        printf("\n----- HTTP POST response -----\n");
        string dataRet = dump_response(post_res);
 
        delete get_req;
        return stoi(dataRet) ;
}
 

const char *sec2str(nsapi_security_t sec)
{
    switch (sec) {
        case NSAPI_SECURITY_NONE:
            return "None";
        case NSAPI_SECURITY_WEP:
            return "WEP";
        case NSAPI_SECURITY_WPA:
            return "WPA";
        case NSAPI_SECURITY_WPA2:
            return "WPA2";
        case NSAPI_SECURITY_WPA_WPA2:
            return "WPA/WPA2";
        case NSAPI_SECURITY_UNKNOWN:
        default:
            return "Unknown";
    }
}

int scan_demo(WiFiInterface *wifi)
{
    WiFiAccessPoint *ap;

    printf("Scan:\n");

    int count = wifi->scan(NULL,0);

    if (count <= 0) {
        printf("scan() failed with return value: %d\n", count);
        return 0;
    }

    /* Limit number of network arbitrary to 15 */
    count = count < 15 ? count : 15;

    ap = new WiFiAccessPoint[count];
    count = wifi->scan(ap, count);

    if (count <= 0) {
        printf("scan() failed with return value: %d\n", count);
        return 0;
    }

    for (int i = 0; i < count; i++) {
        printf("Network: %s secured: %s BSSID: %hhX:%hhX:%hhX:%hhx:%hhx:%hhx RSSI: %hhd Ch: %hhd\n", ap[i].get_ssid(),
               sec2str(ap[i].get_security()), ap[i].get_bssid()[0], ap[i].get_bssid()[1], ap[i].get_bssid()[2],
               ap[i].get_bssid()[3], ap[i].get_bssid()[4], ap[i].get_bssid()[5], ap[i].get_rssi(), ap[i].get_channel());
    }
    printf("%d networks available.\n", count);

    delete[] ap;
    return count;
}


string card_data;

int main()
{
    //Init all chips and ethernet
    //-------------------------------------
    TCPSocket* socketa = new TCPSocket();
    RfChip.PCD_Init();
    wifi = WiFiInterface::get_default_instance();
    //-------------------------------------

    //starting wifi
    //--------------------------------
    if (!wifi) {
        printf("ERROR: No WiFiInterface found.\n");
        return -1;
    }

    printf("\nConnecting to %s...\n", MBED_CONF_APP_WIFI_SSID);
    int ret = wifi->connect(MBED_CONF_APP_WIFI_SSID, MBED_CONF_APP_WIFI_PASSWORD, NSAPI_SECURITY_WPA_WPA2);
    if (ret != 0) {
        printf("\nConnection error: %d\n", ret);
        return -1;
    }

    printf("Success\n\n");
    printf("MAC: %s\n", wifi->get_mac_address());
    printf("IP: %s\n", wifi->get_ip_address());
    printf("Netmask: %s\n", wifi->get_netmask());
    printf("Gateway: %s\n", wifi->get_gateway());
    printf("RSSI: %d\n\n", wifi->get_rssi());
    nsapi_error_t open_result = socketa->open(wifi);
    printf("\nDone\n");
    //--------------------------------

    value = 0;
    consta = 3;
    //main cycle
    //--------------------------------
    while (1) {
        while (! RfChip.PICC_IsNewCardPresent()) {
                    cala.read();
        
        show_temp(to_string(cala.getCelsius()));
        show_helt(to_string(cala.getHumidity()));
        continue;
        }
        calla(to_string(0000));
        calla_alt(to_string(0000));
        RfChip.PICC_ReadCardSerial();
        printf("Card Reader 1: ");
        for (uint8_t i = 0; i < RfChip.uid.size; i++) {
            card_data += to_string(RfChip.uid.uidByte[i]) + ' ';
            printf(" %X", RfChip.uid.uidByte[i]);
        }
        printf("\n\r");
        
        /*
        nsapi_error_t connect_result = socketa->connect("192.168.1.72", 5000);
        std::vector<std::string> card_id {};
        card_id.push_back("id");
        card_id.push_back(card_data);

        sendData(card_id, socketa);
        card_data = "";
        */
        int itterations = 15;
        int current = 0;
        bool checker = false, checker_check = false;
        consta = 15;
        while (current != 2*itterations) {
        calla(to_string(current/2));
        calla_alt(to_string(sensor.distance()));
                 long distance = sensor.distance();   
      pc.printf("distanza  %d  \n",distance);
        wait_us(250000);
            if (checker && checker_check)
            {
                current++;
                checker = false;           
                checker_check = false;
            }
            else {
            if (sensor.distance() > 50)
            {
                checker = true;
            }
            if (sensor.distance() < 5) {
                checker_check = true;
            }
            printf("\n");
            }

        }
        consta = 0;
        printf("train stop");
        value = 0;
        
    }
    //--------------------------------

}
/*
    
 
    myled = 1;
    wait_us(100);
    myled = 0;
    bool checker = false, checker_check = false;
    std::vector<std::string> nota;
    std::vector<std::string> tempa;
    int iterrations = 0;
    bool first = true;
  while(1) {   
      if (checker && checker_check)
      {
          checker = false;
          iterrations++;
          checker_check = false;
      }
      else {
 
      }
      //printf("%li", sensor.distance())   ;
 
        if (sensor.train(train)) {
            myled = 1;
            checker = true;
        }   
        else {
            myled = 0;
        }
        if (sensor.distance() < 10) {
        checker_check = true;
        }
        wait_ms(500);
        printf("%i", iterrations);
        printf("\n");
        if (iterrations == 3)
        {
            if( first )
            {
nota.push_back("id");
nota.push_back("12");
first = false;
iterrations = 0;
 
            }
            // Короче тут трабл
            //пока еще упражнение не сделаешь иттерации будут на 6 
            // А значит постоянно будут отправляться данные
            //
            //
            //
            //nota.push_back(to_string(iterrations));
           nsapi_error_t connect_result = socketa->connect("192.168.1.72", 5000);
           sendData(nota, socketa);
 
            //sendData(nota, socketa);
        }
  }
}

}

 WiFi Example
 * Copyright (c) 2016 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 

 
//D12 TRIGGER D11 ECHO
 
 
//#include <unistd.h>

 

 

 



 

 
    // Open a socket on the network interface, and create a TCP connection to ifconfig.io
 
 

