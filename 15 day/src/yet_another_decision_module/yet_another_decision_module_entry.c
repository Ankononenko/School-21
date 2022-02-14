#include "decision.h"

void main()
{
    double *data;
    int n;
    
    if (make_decision(data, n))
        printf("YES"); 
    else
        printf("NO");  
}
