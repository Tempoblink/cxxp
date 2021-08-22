/*
 * 改写上一题的程序，使用条件运算符（参见4.7节，第134页）代替if else语句。
 *
 * (a) if (ival1 != ival2)
 *        ival1 = ival2
 *        else ival1 = ival2 = 0;
 * (b) if (ival < minval)
 *        minval = ival;
 *        occurs = 1;
 * (c) if (int ival = get_value())
 *        cout << "ival = " << ival << endl;
 *     if (!ival)
 *        cout << "ival = 0 \n";
 * (d) if (ival = 0)
 *        ival = get_value();
 */

/*
 * (a) if (ival1 != ival2)
 *        ival1 = ival2;     //加;
 *        else ival1 = ival2 = 0;
 * (b) if (ival < minval) {
 *        minval = ival;
 *        occurs = 1;
 *     }
 *     int val;
 * (c) if (ival = get_value())
 *        cout << "ival = " << ival << endl;
 *     if (!ival)
 *        cout << "ival = 0 \n";
 * (d) if (ival == 0)
 *        ival = get_value();
 */


int main(void) {
    return 0;
}
