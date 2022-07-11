#pragma once
#include "Movie.h"

typedef enum
{
    ADD, DELETE, UPDATE

}operationType;

class Operation
{
private:
    
    operationType op_type;
    Movie op_coat;
    Movie additional;

public:
    Operation() = default;
    explicit Operation(operationType , Movie , Movie );
    operationType getType(){return this->op_type; }
    Movie getOpCoat(){return this->op_coat; }
    Movie getAdditional(){return this->additional; }
};
