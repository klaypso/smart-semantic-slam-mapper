#ifndef TRACK_H
#define TRACK_H

/**
  * the tracker
  * Tracker跟踪当前输入的帧, 在丢失的时候进行重定位
  * 单纯使用tracker时可能会漂移，它需要后端pose graph提供一个重定位
  * 
  * 算法描述
  * 