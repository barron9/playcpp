#include <stdio.h>
//#include <curl/curl.h>
#include <iostream>
#include "time.h"

int main(void) {
    clock_t start, end;
    time_t startt,endt,timer;
    time(&timer);

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