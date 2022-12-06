
# Project Vizualization
A tool to help vizualize the representation of data structures
in computer memory.

### Graphs


```mermaid

  classDiagram

    data_structures --> linear
    data_structures --> non_linear

    linear --> array
    linear --> stack
    linear --> queue
    linear --> linked_list
    linear --> heap

    non_linear --> graph
    non_linear --> tree

class data_structures{
    // this is a pure virtual class
    +enums [ linear, non-linear ]
    +take_input() // pure vitual function
    +build()      // pure vitual function
    +display()    // pure vitual function
  }
  
class linear{
// this is a pure virtual class
+enums [ array, stack, queue, linked_list, heap]

}

class non_linear{
// this is a pure virtual class
+enums [ graph, tree]

}



```

