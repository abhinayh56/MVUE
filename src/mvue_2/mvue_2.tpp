#include "mvue_2.h"

template <typename T>
estimators::mvue::MVUE_2<T>::MVUE_2()
{
}

template <typename T>
estimators::mvue::MVUE_2<T>::~MVUE_2()
{
}

template <typename T>
void estimators::mvue::MVUE_2<T>::init(T var_1_, T var_2_)
{
    set_param(var_1_, var_2_);
}

template <typename T>
void estimators::mvue::MVUE_2<T>::set_param(T var_1_, T var_2_)
{
    var_1 = var_1_;
    var_2 = var_2_;
}

template <typename T>
T estimators::mvue::MVUE_2<T>::update(T x1_i, T x2_i)
{
    return ((x1_i / var_1) + (x2_i / var_2)) / ((1.0 / var_1) + (1.0 / var_2));
}

template <typename T>
void estimators::mvue::MVUE_2<T>::reset()
{
}
