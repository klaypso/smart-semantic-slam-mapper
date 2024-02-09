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
            fin.open("../para