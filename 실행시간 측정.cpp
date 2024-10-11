#include <time.h>


clock_t start, end;
start = clock();

end = clock();
double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
cout << "실행 시간: " << elapsed_time << "초" << endl;
