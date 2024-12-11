package prompt;
// package llm;


import java.io.IOException;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.nio.charset.StandardCharsets;

class TestInputWriter {
    // Static field for generating random values

    /**
     * Generates a unique filename based on the given prefix and hashcode based 
     * on the current system nano time.
     * @param prefix The prefix to be used in the filename to recognise the system
     *               generating it.
     * @return A unique filename.
     */	
    private static String generateFilename(String prefix) {
        return prefix + System.nanoTime() + ".c";
    }

    /**
     * Writes the provided content to the specified file using java.nio.file.
     * @param filename The name of the file to write content to.
     * @param content The content to be written to the file.
     * @return true if the write operation is successful, false otherwise.
     */	
    private boolean writeFile(String filename, String content) {
        // Writing content to the specified file
        try {
            // Using java.nio.file to write to the file
            byte[] contentBytes = content.getBytes(StandardCharsets.UTF_8);
            Files.write(Path.of(filename), contentBytes, StandardOpenOption.CREATE, StandardOpenOption.WRITE);
        } catch (IOException e) {
            System.err.println("Error writing to the file: " + e.getMessage());
            return false;
        }
        return true;
    }

    /**
     * Compiles with GCC the C code from the specified file into an executable binary.
     * @param filename The name of the C code file to be compiled.
     * @param objName The name of the output binary file.
     * @return true if the compilation is successful, false otherwise.
     */	
    // input_test_bit_binary : inpupt_test_bit
    private boolean generateBinary(String filename, String objName) {
        try {
            String[] compilationCommand = {"gcc", "-O3", filename, "-o", objName};
            ProcessBuilder processBuilder = new ProcessBuilder(compilationCommand);
            processBuilder.redirectErrorStream(true);
            Process process = processBuilder.start();
            return (0 == process.waitFor());
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
            return false;
        }
    }

    /**
     * Writes the test input files for gem5 testing, including C program file, executable binary,
     * input test file, and type file.
     * @param program The C code of the program to be tested.
     * @param callLine The command line arguments for the program.
     * @param argsType The type of arguments expected by the program.
     * @return true if the test input files are successfully created, false otherwise.
     */
    public boolean writeTest(String program, String callLine, String argsType) {
	// If missing data - exit.
      	if (argsType.isEmpty() || callLine.isEmpty() || program.isEmpty()) {
        	System.out.println(">>> Bad program. Skip this test input.");
		return false;
	}

	// Try to write the test
	String fileNameC = generateFilename("test_input_");
	String fileNameObj = fileNameC + ".o";
	String fileNameType = fileNameC + ".type";
	String fileNameInput = fileNameC + ".txt";

	// Try to write the C program as a file
    	if (!writeFile(fileNameC, program)) {
		System.out.println("File Write Failed: program");
		return false;
	}

	// Try to generate the binary
	if (!generateBinary(fileNameC, fileNameObj)) {
		System.out.println("File Write Failed: Binary");
		return false;
	}

	// Try to write the Input test (as we will give it to gem5)
	String testArgs = fileNameObj + "\n" + callLine;
        if (!writeFile(fileNameInput, testArgs)) {
		System.out.println("File Write Failed: Fuzz data");
		return false;
	}

      	// Try to write the type file
     	if (!writeFile(fileNameType, argsType)) {
		System.out.println("File Write Failed: Type");
		return false;
	}
        return true;
    }
}
