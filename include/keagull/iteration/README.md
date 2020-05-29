# Iteration

In `keagull`, iteration is done using two basic constructs: the `while_predicate()` function and the `forward_iterable()` function.

A class is called an `Iterable` if it provides a `void while_predicate(UnaryPredicate P)` function.

A class is called an `IterableProxy` if it provides a `auto forward_iterable(Iterable it)` function.

Iteratables can be "forwarded", using the provided `operator>>` overload:

```cpp
template <class Iterable, class IterableProxy>
auto operator>>(Iterable it, IterableProxy pr) {
    return pr.forward_iterable(it);
}
```

Leading to expressions like:

```cpp
process_list.iterable()
    >> filter([](const auto& x) { return x.is_wow64(); })
    >> transform([](const auto& x) { return x.pid(); })
    >> for_each(kill_pid);
```

There are multiple proxies provided by `keagull`, such as:

* [X] `transform(UnaryFunction) -> Iterable`
* [X] `filter(UnaryPredicate) -> Iterable`
* [X] `all(UnaryPredicate) -> bool`
* [X] `none(UnaryPredicate) -> bool`
* [X] `any(UnaryPredicate) -> bool`
* [X] `for_each(UnaryFunction) -> void`
* [X] `fold(BinaryFunction, T) -> S`
* [ ] `take_while(UnaryPredicate) -> Iterable`
* [ ] `skip_while(UnaryPredicate) -> Iterable`
