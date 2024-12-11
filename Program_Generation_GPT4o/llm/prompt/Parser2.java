package prompt;


import java.util.regex.*;

class Parser2 {

    // Try to extract the code
    private String getCode(String input, String cCodeRegex) {
        String[] lines = input.split("\\r?\\n");
        if (1 > lines.length) return "";
        try {
            Pattern cPattern = Pattern.compile(cCodeRegex, Pattern.DOTALL);

            // Get the block
            int i = 0;
            Matcher cMatcher = cPattern.matcher(lines[0]);
            // Print C code blocks
            while (!cMatcher.find()) {
                i++;
                if (i > lines.length) return "";
                cMatcher = cPattern.matcher(lines[i]);
            }
            // Yeah! we found it!
            // Jump to the start (we do not need the first i matched
            i++;

            // Pattern and Matcher for end of Code code
            if (i > lines.length) return "";
            String cCodeRegexEnd = "```*";
            Pattern cPatternEnd = Pattern.compile(cCodeRegexEnd, Pattern.DOTALL);
            Matcher cMatcherEnd = cPatternEnd.matcher(lines[i]);
            String program = "";
            while (!cMatcherEnd.find()) {
                program += "\n" + lines[i];
                i++;
                if (i > lines.length) return "";
                cMatcherEnd = cPatternEnd.matcher(lines[i]);
            }
            return program;
        } catch (PatternSyntaxException | ArrayIndexOutOfBoundsException e) {
            return "";
        }
    }
    
    // C program extractor
    public String getCProgram(String res) {
        String CString = (res.contains("```c*") ? "```c*" : "```C*");
        return getCode(res, CString);
    }

}

