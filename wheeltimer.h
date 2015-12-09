/*********************************************************************
	> File Name: wheeltimer.h
	> Author: 彭治湘
	> Mail: 345109788@qq.com 
	> Created Time: Wednesday 09 December 2015 05:36:30 PM CST
 ********************************************************************/

#ifndef _WHEELTIMER_H
#define _WHEELTIMER_H

//时间轮定时器
class WheelTimer
{
    public:
    WheelTimer();
    ~WheelTimer();

    WheelTimer* GetPrev();
    WheelTimer* GetNext();

    WheelTimer SetPrev(WheelTimer* prev);
    WheelTimer SetNext(WheelTimer* next);

    void OnTimer();

    uint32_t GetRemain() const;
    void SetRemain(uint32_t remain);
    void OnSchedule(WheelNode* node);

    bool Schedule(TimerTask* task,uint32_t minsec);
    void Destroy();

    private:
    TimerTask* m_task;  //定时任务
    WheelNode* m_node;  //轮子的槽
    uint32_t m_remain;  //剩余的时间
    WheelTimer* m_prev; //前一个定时器
    WheelTimer* m_next; //后一个定时器

};

#endif //_WHEELTIMER_H
