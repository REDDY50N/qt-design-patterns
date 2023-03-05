# README

- Design Patterns (Gang of 4)
- 23 approaches

## Design Pattern

1. Creational Patterns - How objects are created
2. Structural Patterns - How objects relate to each other
3. Behavioral Patterns - How objects communicate with each other

 
## Creational Patterns

### Singleton

- for global app settings
- static instance
- private ctor (cannot instanciated with new)
- static getInstance methods, whichs checks if instance is still created, otherwise create a new one

### Prototype

- clone objects
- alternative way to implement inheritance
- but inherits from an already created object
- flatter hirachy 
- object.create(<zombie>, 'chad')
- object.getPrototypOf(<chad>)

### Builder
**Purpose:** avoiding monstrous constructor initialization

**How it works:**
- we can define all options in the ctor
- with builder pattern we create the object step by step with methods

```c++
class DebugLogger {
public:
    HotDog();
    
    void addConsole(){
        this.consoleLog = true;
    }

    void addUDP(){
        this.udpLog = true;
    }
    
    void addLogFile(){
        this.logfile = true;
    } 
 private:
    // ...
};

```

**Further reading:**
https://thecodeprogram.com/explanation-of-builder-design-pattern-with-c--

### Factory

**Purpose:** creating objects in a superclass, but allows subclasses to change the type of objects that will be created

**How it works:**
- use a function instead of using `new` to create an object
- create objects with different options
- i.e. builds motor veheciles => option: truck or car  
- i.e. button option for windows or unix

### Abstract Factory


### 


## Further experiments
- Multithreading - Problem with accessing shared ressources
- Simultaneous access to shared resources 
- Different threads access shared data at the same time
==> conflicts, if access is not atomic:
==> one Threads writes data, other Thread wants to read data

Atomic Threads:
https://stackoverflow.com/questions/46172607/qt-singleton-implementation
https://www.youtube.com/watch?v=e1SNT-hxs8E
