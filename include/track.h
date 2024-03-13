#ifndef TRACK_H
#define TRACK_H

/**
  * the tracker
  * Tracker跟踪当前输入的帧, 在丢失的时候进行重定位
  * 单纯使用tracker时可能会漂移，它需要后端pose graph提供一个重定位
  * 
  * 算法描述
  * Tracker内部有初始化、跟踪成功和丢失三个态
  * 每次用updateFrame放入一个新帧，记为F
  * Tracker把新帧F与它自己维护的一个候选队列里的参考帧相匹配。建立Local bundle adjustment.
  * Local BA是一个简易的pose graph.
  * 匹配成功时，把当前帧作为新的候选帧，放到候选队列末尾。如果队列太长则删除多余的帧。
  *