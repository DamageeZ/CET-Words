/**
* Created by zhouzhm1 on 2021/9/27.
*/

#ifndef CET_CURRENTDTO_H
#define CET_CURRENTDTO_H

struct currentDTO       //用户状态传递，去除密码数据
{
    char UserName[20];
    unsigned int Id = 0;
    unsigned int level = 0;
    unsigned int score = 0;
    int lastSignTime = 0;
    int dateOfToday = 0;
};

#endif //CET_CURRENTDTO_H
