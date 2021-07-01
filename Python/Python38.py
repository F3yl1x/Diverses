from typing import Literal


def incr(x):
    return x + 1

class Python38:

    # Scenario 1
    def new_feature_walrus_operator(self) -> None:
        lines = []
        while current_line != "quit":
            lines.append(current_line := input("Tell me something: "))

        """
            Some more information
            Seen and loved. Especially for the here used use case of initializing and 
            updating variables in loops. Of course you have to take care that the lines 
            remain readable. 
        """
    
    # Scenario 2
    def new_feature_positional_only_arguments(self) -> None:
        _ = incr(x=1)
        
        """
            Some more information: 
            Before Python 3.8 positional only arguments was implemented only for 
            build in methods like float(). From now on you can do this for your 
            own functions. Fun fact: For keyword only arguments this has been possible 
            for quite some time (with the * instead of /)
        """
    
    from typing import Literal

    # Scenario 3
    def new_feature_more_type_annotations(self, language: Literal["DE","EN"]) -> None:
        if language == "DE":
            print("Hallo Welt")
        elif language == "EN":
            print("Hello World")
            
        """
            Some more information: 
            Beside the new literal type there are some more new types, e.g. the TypedDict. 
            These annotations do not cause the program to crash at runtime if they are ignored, 
            but give type checkers a basis to detect type conflicts. They also make your code 
            more readable.
        """
    
    # Scenario 4
    def new_feature_more_improved_f_string(self) -> None:
        a, b = (4, 4)
        f'{sum}'
            
        """
            Some more information:
            A small but nice improvement of the f-string. In general f-strings are a great feature in Python. 
            The combination of strings and variables is so clean, like hardly in any other language.
        """