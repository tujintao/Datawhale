class Solution {
public:
int mySqrt(int x) {
   long long  lo = 0;
   long long hi = x ;
   while(lo < hi) {
      long long mid = lo + (hi - lo)/2;
      if(mid * mid > x){
         hi = mid;
      } else {
         lo = mid + 1;
      }
   }
   if(lo * lo == x)
       return lo;
    return lo - 1;
}
};