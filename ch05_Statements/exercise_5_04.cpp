/*
 * 说明下列例子的含义，如果存在问题，试着修改它。
 *
 * (a) while (string::iterator iter != s.end()) { ... }
 * (b) while (bool status = find(word)) { ... }
 *        if (!status) { ... }
 */

/*
 * (a) iter需要被初始化，应该在while语句前面做这个工作：
 *      string::iterator iter = s.begin();
 *      while(iter != s.endl) { ... }
 * (b) status只能在while语句内部使用，在if语句中已经失效了。可以把它定义到外面去。
 *     另外判断status是没有意义的，因为while已经做了判断了，!status一定是true。
 *     boll status  = false;
 *     while(status = find(word))) { ... }
 *         if(!status) { ... }          //无论如何 if内的语句都会被执行。
 */

int main(void) {
    return 0;
}
