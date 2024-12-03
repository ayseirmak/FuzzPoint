

 self.system_prompt = """
        You are a highly specialized assistant for transforming and simplifying C programs to meet specific requirements. Your task is to rewrite given C programs so they are ARM-compatible and deterministic. All outputs must adhere strictly to the following guidelines:
        1. **ARM Compatibility**: Ensure the code can run on ARM architecture without any architecture-specific incompatibilities.
        2. **No Reading Operations**: Exclude any code that uses functions like `scanf`, file I/O, or similar input mechanisms.
        3. **No Time Functions or Randomness**: Avoid using time-based functions (e.g., `time()`, `gettimeofday()`) or randomness (`rand()`, `srand()`). Outputs must not rely on any non-deterministic behavior.
        4. **No Uninitialized Variables**: Initialize all variables explicitly before use.
        5. **Deterministic Inputs**: Replace any dynamic or nondeterministic inputs with fixed values defined directly within the program.
        6. **Standard Compliance**: Replace custom verifier functions or non-standard libraries with standard C constructs (e.g., assertions, logging with `printf`).
        Your output must be clean, understandable, and maintain functional equivalence to the original program within the specified constraints.
        """

query = """
                Can you convert this program to the normal program. 
                Please ensure the transformed program meets the following criteria:
                1. It is ARM-compatible.
                2. It excludes all reading operations such as `scanf` or file I/O.
                3. It avoids using time functions, randomness, or uninitialized variables.
                4. It ensures that input values are deterministic and fixed within the program.
                5. It uses standard C constructs (e.g., `assert`, `printf`) for errors or debugging.

                Provide a fully transformed and self-contained program that meets these requirements. 

                Here’s the code that needs transformation:
        """
        '''
        Please ensure the transformed program meets the following criteria:
            1. It is ARM-compatible.
            2. It excludes all reading operations such as `scanf` or file I/O.
            3. It avoids using time functions, randomness, or uninitialized variables.
            4. It ensures that input values are deterministic and fixed within the program.
            5. It uses standard C constructs (e.g., `assert`, `printf`) for errors or debugging.
            Provide a fully transformed, simple and self-contained program that meets these requirements.
        '''