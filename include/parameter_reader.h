#ifndef PARAMETER_READER_H
#define PARAMETER_READER_H
#include "common_headers.h"

namespace rgbd_tutor
{
struct CAMERA_INTRINSIC_PARAMETERS;

class ParameterReader
{
public:
    ParameterReader( string filename="./parameters.txt" )
    {
        ifstream fin( filename.c_str() );
        if (!fin)
        {
            // try ../parameter.txt
            fin.open("../parameters.txt");
            if (!fin)
            {
                cerr<<"parameter file does not exist."<<endl;
                return;
            }
        }
        while(!fin.eof())
        {
            string str;
            getline( fin, str );
            if (str[0] == '#')
            {
                // 以‘＃’开头的是注释
                continue;
            }
            int pos