# chrono

## Time library
chrono is the name of a header, but also of a sub-namespace: All the elements in this header (except for the common_type specializations) are not defined directly under the `std` namespace (like most of the standard library) but under the `std::chrono` namespace.

The elements in this header deal with time. This is done mainly by means of three concepts:

## Durations

They measure time spans, like: one minute, two hours, or ten milliseconds.
In this library, they are represented with objects of the `duration` class template, that couples a count representation and a period precision (e.g., ten milliseconds has ten as count representation and milliseconds as period precision).

##Time points

A reference to a specific point in time, like one's birthday, today's dawn, or when the next train passes.
In this library, objects of the `time_point` class template express this by using a `duration` relative to an epoch (which is a fixed point in time common to all time_point objects using the same clock).

##Clocks

A framework that relates a time point to real physical time.
The library provides at least three clocks that provide means to express the current time as a `time_point` : `system_clock`, `steady_clock` and `high_resolution_clock`.

For typical examples, see steady_clock or system_clock.

