#include <cstdio>
//#include <curl/curl.h>
#include <iostream>
#include <cstring>
#include <ctime>

#include "employee.h"

/* Return 1 if c is part of string s; 0 otherwise */
int is_in(char *s, char c[]);


int main(void) {
    employee e;
    e.getwage();
    clock_t start, end;
    time_t startt,endt,timer;
    time(&timer);


    char c[] = "asd" ;
    char a[2][11];
    std::cout<<"type something to send buffer : "<< "\n";
    gets(c);
    std::cout<<"what entered is in length of : "<< strlen(c) <<"\n";

    for(int y = 0 ; y<strlen(c);y++) std::cout<<c[y]<<"\n";
    strcpy(a[0], c);
    strcpy(a[1], c);

    std::cout<<"what entered is : "<< a[1] <<"\n";

    unsigned long int b = 0;
    start = clock();
    startt = time(NULL);

    for (long int a = 0; a < INT_MAX; ++a) {
        b=a;
    }

    std::cout<<b<<"\n";
    end = clock();
    endt = time(NULL);
    std::cout <<   endt - startt<< " time_t seconds" << "\n";
    std::cout << (int) end - start << " clock_t seconds" << "\n";
    std::cout <<  CLOCKS_PER_SEC << " clockpersec" << "\n";
    /*    CURL *curl;
    CURLcode res;
    std::cout << "start\n";
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://google.com");
        *//* example.com is redirected, so we tell libcurl to follow redirection *//*
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        *//* Perform the request, res will get the return code *//*
        res = curl_easy_perform(curl);
        *//* Check for errors *//*

        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        *//* always cleanup *//*
        curl_easy_cleanup(curl);
    }*/
    return 0;
}
int is_in(char *s, char c[])
{
    std::cout <<" -~~ "<< *s;
    while(*s)
        if(*s==c[0]) return 1;
        else s++;
    return 0;
}