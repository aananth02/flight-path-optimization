 #include "utilities.h"
 float distance(float latitude1, float longitude1, float latitude2, float longitude2){
    latitude1 *= (3.14) / 180;
    longitude1 *= (3.14) / 180;
    latitude2 *= (3.14) / 180;
    longitude2 *= (3.14) / 180;
    float ans = pow(sin((latitude2 - latitude1) / 2), 2) +
                          cos(latitude1) * cos(latitude2) *
                          pow(sin((longitude2 - longitude1) / 2), 2);

    ans = 6371 * 2 * asin(sqrt(ans));
    return ans;
}