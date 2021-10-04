#pragma once
#include <string>
#include <iostream>

struct Pipe
{
    int id;
    double length;
    double diameter;
    bool in_process;
};

struct  Station
{
    int id;
    std::string name;
    int num;
    int num_process;
    int eff;
};

void print_pipe(Pipe& pipe);

void print_station(Station& station);

void print_menu();

void input_station(Station& station);

void input_pipe(Pipe& pipe);
