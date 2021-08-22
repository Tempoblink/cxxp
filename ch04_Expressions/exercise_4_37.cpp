/*
 * 用命名的强制类型转换改写下列旧式的转换语句。
 *
 * int i; double d; const string *ps; char *pc; void *pv;
 *
 * (a) pv = (void*)ps;                (b) i = int(*pc);
 * (c) pv = &d;                       (d) pc = (char*)pv;
 */

/*
 * (a) pv = static_cast<void*>(const_cast<string*>(ps));
 * (b) i = static_cast<int>(*ps);
 * (c) pv = static_cast<void*>(&d);
 * (d) pc = reinterpret_cast<char*>(pv);     
 * 由于pv是void*型指针，不确定指向的对象的是什么类型，
 * 如果指向对象与pc不同，则应是 reinterpret_cast;
 * 如果指向对象与pc相同，则可以是static_cast;
 */

int main(void) {
    return 0;
}
