#pragma once

namespace keagull
{

    // std::integral_constant
    template <class T, T v>
    struct integral_constant
    {
        static constexpr T value = v;
        using value_type = T;
        using type = integral_constant;
        constexpr operator value_type() const noexcept { return value; }
        constexpr value_type operator()() const noexcept { return value; }
    };

    // std::bool_constant
    template <bool B>
    using bool_constant = integral_constant<bool, B>;

    using false_type = bool_constant<false>;
    using true_type = bool_constant<true>;

    // std::is_lvalue_reference
    template <class T>
    struct is_lvalue_reference : false_type
    {
    };
    template <class T>
    struct is_lvalue_reference<T &> : true_type
    {
    };

    template <class T>
    inline constexpr bool is_lvalue_reference_v = is_lvalue_reference<T>::value;

    // my implementation for std::remote_reference
    template <class T>
    struct remove_reference
    {
        using type = T;
    };
    template <class T>
    struct remove_reference<T &>
    {
        using type = T;
    };
    template <class T>
    struct remove_reference<T &&>
    {
        using type = T;
    };

    template <class T>
    using remove_reference_t = typename remove_reference<T>::type;

    // my implementation for std::is_same
    template <class T, class U>
    struct is_same : public false_type
    {
    };
    template <class T>
    struct is_same<T, T> : public true_type
    {
    };

    // my implementations for std::{remove_const, remove_volatile, remove_cv}
    template <class T>
    struct remove_cv
    {
        using type = T;
    };
    template <class T>
    struct remove_cv<const T>
    {
        using type = T;
    };
    template <class T>
    struct remove_cv<volatile T>
    {
        using type = T;
    };
    template <class T>
    struct remove_cv<const volatile T>
    {
        using type = T;
    };

    template <class T>
    using remove_cv_t = typename remove_cv<T>::type;

    template <class T>
    struct remove_const
    {
        using type = T;
    };
    template <class T>
    struct remove_const<const T>
    {
        using type = T;
    };

    template <class T>
    using remove_const_t = typename remove_const<T>::type;

    template <class T>
    struct remove_volatile
    {
        using type = T;
    };
    template <class T>
    struct remove_volatile<volatile T>
    {
        using type = T;
    };

    template <class T>
    using remove_volatile_t = typename remove_volatile<T>::type;

    // my implementation for std::is_pointer
    template <class T>
    struct is_pointer_helper : public false_type
    {
    };
    template <class T>
    struct is_pointer_helper<T *> : public true_type
    {
    };

    template <class T>
    struct is_pointer : public is_pointer_helper<typename remove_cv<T>::type>
    {
    };

    template <class T>
    inline constexpr bool is_pointer_v = is_pointer<T>::value;

    // my implementation for std::is_reference
    template <class T>
    struct is_reference : public false_type
    {
    };
    template <class T>
    struct is_reference<T &> : public true_type
    {
    };
    template <class T>
    struct is_reference<T &&> : public true_type
    {
    };

    template <class T>
    inline constexpr bool is_reference_v = is_reference<T>::value;

    // my implementation for std::conditional
    template <bool B, class T, class F>
    struct conditional
    {
        using type = T;
    };
    template <class T, class F>
    struct conditional<false, T, F>
    {
        using type = T;
    };

    template <bool B, class T, class F>
    using conditional_t = typename conditional<B, T, F>::type;
} // namespace keagull
