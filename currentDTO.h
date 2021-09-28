//
// Created by zhouzhm1 on 2021/9/27.
//

#ifndef CET_CURRENTDTO_H
#define CET_CURRENTDTO_H
struct currentDTO {
    char UserName[20];
    unsigned int Id = 0;
    unsigned int level = 0;
    unsigned int score = 0;
    short lastSignTime = 0;
    short dateOfToday = 0;
};

#endif //CET_CURRENTDTO_H
