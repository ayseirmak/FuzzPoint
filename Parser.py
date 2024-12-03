import re

class Parser:
    def get_code(self, input_text, c_code_regex):
        lines = input_text.splitlines()
        if len(lines) < 1:
            return ""

        try:
            c_pattern = re.compile(c_code_regex, re.DOTALL)
            
            # Get the block
            i = 0
            c_matcher = c_pattern.match(lines[0])
            
            # Find the first line matching the C code block regex
            while not c_matcher:
                i += 1
                if i >= len(lines):
                    return ""
                c_matcher = c_pattern.match(lines[i])
            
            # Move to the next line after the match
            i += 1

            # Define the end pattern for the C code block
            if i >= len(lines):
                return ""
            
            c_code_regex_end = r"```*"
            c_pattern_end = re.compile(c_code_regex_end, re.DOTALL)
            c_matcher_end = c_pattern_end.match(lines[i])
            program = ""

            # Extract the code until the end pattern is found
            while not c_matcher_end:
                program += "\n" + lines[i]
                i += 1
                if i >= len(lines):
                    return ""
                c_matcher_end = c_pattern_end.match(lines[i])
            
            return program.strip()

        except (re.error, IndexError):
            return ""

    def get_c_program(self, res):
        c_string = "```c*" if "```c*" in res else "```C*"
        return self.get_code(res, c_string)