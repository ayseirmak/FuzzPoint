package prompt;


import prompt.LLMTokensOptions;
import prompt.Parser;
import prompt.TestInputWriter;

class QueryGenerator {
    public static void main(String[] args) {

    	if (args.length > 3) {
            System.out.println("Please provide a single parameter (0, 1, or 2).");
            // Optionally, you can exit the program here if the number of parameters is incorrect
            System.exit(1);
        }

	// Parse the parameter as an integer
        int parameter;
        try {
            parameter = Integer.parseInt(args[1]);
        } catch (NumberFormatException e) {
            System.out.println("Invalid parameter. Please provide a valid integer (0, 1, or 2).");
            System.exit(1);
            return; // Unreachable, but included for clarity
        }

        // Check if the parameter is within the valid range
        if (parameter < 0 || parameter > 5) {
            System.out.println("Invalid parameter. Please provide a value between 0 and 2 (inclusive).");
            System.exit(1);
        }
/* 
	if (parameter == 0) {
        	// Let LLM know what we want:
        	String promtStart = "Generate a concise C file without unnecessary includes, but with output. The C file should be a standard program, but with a twist:"
                	+ " it replaces all constants in the main function with argument assignments, adds required includes.";
        	promtStart += "Example ```C\n#include <stdio.h>\n#include <stdlib.h>\nint main(int argc, char *argv[]) {\n"
                	+ "  if (argc != 2) {\n    printf(''Usage: %s <value>\n'', argv[0]);\n    return 1;\n  }\n  int x = atoi(argv[1]);\n"
                	+ "  return x - 4;\n}```\nDo you think you can do that?";
       		System.out.println(promtStart);
*/
	if (parameter == 0) {
		// Let LLM know what we want:
		String promptStart = "Generate a C program without unnecessary includes, but with output. The C program should focus on floating-points";
		promptStart += " The program should perform various complex floating-points operations.";
    	promptStart += " Additionally, the program should iclude some of the edge case operations such as rounding behavior, handling of denormalized floating-point numbers, `long long` data type  and `long double` data type, `NaN` (Not-a-Number) and `INF` (infinity) values, as well as underflow and overflow conditions.";
		promptStart +="The code should be optimized for an ARM system, potentially using ARM-specific intrinsics.";
		promptStart += " The output should be deterministic, either 0 or 1. Initialize all variables explicitly before use.";
		promptStart += " The aim is to generate C programs that include various floating point opeartions to analyse the behaviour of GCC compiler with different optimization flags related to floating point operations and edge cases.";
		promptStart += " Avoid using time functions, randomness, or uninitialized variables and excessive printf statements. Ensure that the input values are deterministic and fixed within the program. No reading operations should be performed (e.g., `scanf` or reading from files).";
		promptStart += " Example ```C\n#include <stdio.h>\n#include <math.h>\n"
			+ "// Define a structure to represent an atom in 3D space\n"
			+ "typedef struct {\n"
			+ "    double x, y, z;  // Coordinates of the atom\n"
			+ "    double charge;   // Charge of the atom for interaction computation (e.g., Coulombic)\n"
			+ "} Atom;\n\n"
			+ "// Function to compute the Euclidean distance between two atoms\n"
			+ "double compute_distance(Atom a1, Atom a2) {\n"
			+ "    return sqrt(pow(a1.x - a2.x, 2) + pow(a1.y - a2.y, 2) + pow(a1.z - a2.z, 2));\n"
			+ "}\n\n"
			+ "// Function to compute the interaction between two atoms\n"
			+ "double compute_interaction(Atom a1, Atom a2) {\n"
			+ "    double distance = compute_distance(a1, a2);\n"
			+ "    if (distance == 0) return 0;  // Avoid division by zero\n"
			+ "    // Coulomb's law: interaction ~ (q1 * q2) / distance^2\n"
			+ "    return (a1.charge * a2.charge) / (distance * distance);\n"
			+ "}\n\n"
			+ "int main() {\n"
			+ "    // Example: Molecule with 4 atoms\n"
			+ "    Atom molecule[] = {\n"
			+ "        {0.0, 0.0, 0.0, 1.0},   // Atom 1\n"
			+ "        {1.0, 0.0, 0.0, -1.0},  // Atom 2\n"
			+ "        {0.0, 1.0, 0.0, 1.0},   // Atom 3\n"
			+ "        {1.0, 1.0, 0.0, -1.0}   // Atom 4\n"
			+ "    };\n"
			+ "    int num_atoms = sizeof(molecule) / sizeof(molecule[0]);\n"
			+ "    // Compute pairwise interactions\n"
			+ "    printf(\"Pairwise interactions:\\n\");\n"
			+ "    for (int i = 0; i < num_atoms; i++) {\n"
			+ "        for (int j = i + 1; j < num_atoms; j++) {\n"
			+ "            double interaction = compute_interaction(molecule[i], molecule[j]);\n"
			+ "            printf(\"Interaction between atom %d and atom %d: %f\\n\", i+1, j+1, interaction);\n"
			+ "        }\n"
			+ "    }\n\n"
			+ "    return 0;\n"
			+ "}```\nDo you think you can do that?";
		System.out.println(promptStart);
	}	if (parameter == 3) {
		// Let LLM know what we want:
		String promptStart = "Generate a C program without unnecessary includes, but with output. The C program should focus on floating-points";
		promptStart += " The program should perform various complex floating-points operations.";
		promptStart +="The code should be optimized for an ARM system, potentially using ARM-specific intrinsics.";
		promptStart += " The output should be deterministic, either 0 or 1";
		promptStart += " Avoid using time functions, randomness, or uninitialized variables and excessive printf statements. Ensure that the input values are deterministic and fixed within the program. No reading operations should be performed (e.g., `scanf` or reading from files).";
		promptStart += " Example ```C\n#include <stdio.h>\n#include <math.h>\n"
			+ "// Define a structure to represent an atom in 3D space\n"
			+ "typedef struct {\n"
			+ "    double x, y, z;  // Coordinates of the atom\n"
			+ "    double charge;   // Charge of the atom for interaction computation (e.g., Coulombic)\n"
			+ "} Atom;\n\n"
			+ "// Function to compute the Euclidean distance between two atoms\n"
			+ "double compute_distance(Atom a1, Atom a2) {\n"
			+ "    return sqrt(pow(a1.x - a2.x, 2) + pow(a1.y - a2.y, 2) + pow(a1.z - a2.z, 2));\n"
			+ "}\n\n"
			+ "// Function to compute the interaction between two atoms\n"
			+ "double compute_interaction(Atom a1, Atom a2) {\n"
			+ "    double distance = compute_distance(a1, a2);\n"
			+ "    if (distance == 0) return 0;  // Avoid division by zero\n"
			+ "    // Coulomb's law: interaction ~ (q1 * q2) / distance^2\n"
			+ "    return (a1.charge * a2.charge) / (distance * distance);\n"
			+ "}\n\n"
			+ "int main() {\n"
			+ "    // Example: Molecule with 4 atoms\n"
			+ "    Atom molecule[] = {\n"
			+ "        {0.0, 0.0, 0.0, 1.0},   // Atom 1\n"
			+ "        {1.0, 0.0, 0.0, -1.0},  // Atom 2\n"
			+ "        {0.0, 1.0, 0.0, 1.0},   // Atom 3\n"
			+ "        {1.0, 1.0, 0.0, -1.0}   // Atom 4\n"
			+ "    };\n"
			+ "    int num_atoms = sizeof(molecule) / sizeof(molecule[0]);\n"
			+ "    // Compute pairwise interactions\n"
			+ "    printf(\"Pairwise interactions:\\n\");\n"
			+ "    for (int i = 0; i < num_atoms; i++) {\n"
			+ "        for (int j = i + 1; j < num_atoms; j++) {\n"
			+ "            double interaction = compute_interaction(molecule[i], molecule[j]);\n"
			+ "            printf(\"Interaction between atom %d and atom %d: %f\\n\", i+1, j+1, interaction);\n"
			+ "        }\n"
			+ "    }\n\n"
			+ "    return 0;\n"
			+ "}```\nDo you think you can do that?";
		System.out.println(promptStart);

	}else if (parameter == 1) {
		// Set all objects we need
        	//ProgramGenerator compilerStrings = new ProgramGenerator();
        	LLMTokensOptions llmIndexedTokens = new LLMTokensOptions();

            	// Get a random entry from each array
            	String randomCompilerOpt = llmIndexedTokens.getRandomCompilerOpt();
				String randomCompilerParts = llmIndexedTokens.getRandomCompilerParts();
            	String randomConcept = llmIndexedTokens.getRandomConcept();
            	String randomPL = llmIndexedTokens.getRandomPL();

            	// program
            	String prompt = 
			"Coding task: give me a program in C which includes all necessary includes and is related to floating-points and "  + randomConcept + " with intensive computations. Please return a program (C program) and a concrete example of an input (BASH)."
			+ "The program should use fixed values defined directly within the code (no reading operations). It should include various edge case floating-point operations. Avoid using excessive printf statements"
			+ "Additionally, it should include some code snippets that trigger " + randomCompilerOpt + " optimizations in GCC, and it should cover this part of the compiler: " + randomCompilerParts 
			+ ". It must also exercise this concept in C: " + randomPL + " The program should be related to  " + randomConcept + ". "
			+ "To recap, the code should demonstrate complex floating-point operations and include elements like: " + randomCompilerOpt 
			+ " and " + randomCompilerParts + " and " + randomPL;
		System.out.println(prompt);
	} else if (parameter == 4) {
		LLMTokensOptions llmIndexedTokens = new LLMTokensOptions();
			String randomConcept = llmIndexedTokens.getRandomConcept();

			// program
			String prompt = 
		"Coding task: give me a program in C which includes all necessary includes and is related to floating-points and "  + randomConcept + " with intensive floating point operations. Please return a program (C program) and a concrete example of an input (BASH)."
		+ "The program should use fixed values defined directly within the code (no reading operations). Avoid using excessive printf statements."
		+ " The program should be related to  " + randomConcept + ", and floating-points.";
		System.out.println(prompt);
	
	} else if (parameter == 2) {
		LLMTokensOptions llmIndexedTokens = new LLMTokensOptions();
			String randomConcept = llmIndexedTokens.getRandomConcept();
			
			String randomEC_1 = llmIndexedTokens.getRandomEC();
			String randomEC_2 = llmIndexedTokens.getRandomEC();
			String randomEC_3 = llmIndexedTokens.getRandomEC();

			String randomST_1 = llmIndexedTokens.getRandomST();
			String randomST_2 = llmIndexedTokens.getRandomST();
			String randomST_3 = llmIndexedTokens.getRandomST();

			// program
			String prompt = 
		"Coding task: give me a program in C which includes all necessary includes and is related to complex floating-point operations and "  + randomConcept + " with intensive computations. Please return a program (C program) and a concrete example of an input (BASH)."
		+ "The program should include various complex floating point operations and  also floating point edge case operations such as "+ randomEC_1 + ", " + randomEC_2 + ", and " + randomEC_3 + ". These floating point edge cases should incorporate with C structers such as " + randomST_1 + ", " + randomST_2 + ", and " + randomST_3 + "."
		+ "The program should use fixed values defined directly within the code (no reading operations). Avoid using printf statements."
		+ " The program should be related to  " + randomConcept + ", and floating-pointand also floating points operations.";
		System.out.println(prompt);
	
	}else {
	    String res = args[2];
	    if (res.isEmpty()) {
		System.out.println("Invalid parameter. Please provide a result text from LLM model.");
            	System.exit(1);
            }

	    // Create a parser
	    Parser parser = new Parser();

            // Program
            String program = parser.getCProgram(res);

            // Input
            String callLine = parser.getArgsInput(res);

            // Type
            String argsType = parser.getTypes(res, callLine);

	    // Print all
	    System.out.println(argsType);
	    System.out.println(callLine);
	    System.out.println(program);
	}
    }
}
