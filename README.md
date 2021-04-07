# Priority-cache-implementation-with-Doubly-Linked_List

The MyCacheCalculator class, which derives from the BaseFunctionCalculator abstract class, gets rid of being an abstract class by overriding the methods in the abstarct class. In addition, other functions with private access modifier have been added to perform the necessary operations in the class.

Project's Basic features

The capacity variable entered by the user is kept in the class. The value sent to the Calculate function is first searched in the class. If the created data structure is empty or the entered value has not been added to the data structure before, relevant operations are performed in the calculate function and values ​​are added to the data structure. If the value sent as a parameter to the calculate function is already in the data structure, the corresponding value is retrieved from the data structure by searching. In this way, cache logic is provided. However, if the relevant value is sent as a parameter to the calculate function 2 or more times in a sequantially form, the priority of the value entered in the data structure is increased and the relevant value of the entered data returns to the user.
