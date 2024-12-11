package prompt;

import java.util.Random;

class LLMTokensOptions {
    private static final Random random = new Random();

    public final String[] m_compilerOpt = {
        "Constant Folding and Propagation",
        "Loop Unrolling",
        "Vectorization (SIMD Optimization):",
        "Function Inlining",
        "Strength Reduction",
        "Peephole",
        "Reassociation and Algebraic Simplification",
        "Common Subexpression Elimination (CSE)",
        "Dead Code Elimination",
        "Precision Control and Register Spilling",
        "Instruction Scheduling",
        "Floating-Point Contraction (e.g., -ffp-contract=fast)",
        "Profile-Guided Optimization (PGO)",
        "Math Function Optimization",
        "Loop Fusion and Fission",
        "Denormal Number Handling",
        "Floating-Point Exception Optimization",
        "Value Range Propagation (VRP)",

        "Fast-Math Optimizations", 
        "Precise Rounding Control",
        "Signaling NaN Handling", 
        "Handling of Denormalized Numbers",
        "Floating-Point Trapping Control", 
        "Extended Precision Handling",
        "Strict IEEE 754 Compliance", 
        "Relaxed Floating-Point Semantics",
        "Finite Math Optimization", 
        "Associative Math Transformations",
        "Reciprocal Transformation", 
        "Division Optimization",
        "Square Root Approximation", 
        "Trigonometric Function Optimization",
        "Loop Unrolling with Floating-Point", 
        "Vectorization of Floating-Point Operations",
        "SIMD Optimizations for Floating-Point", 
        "Complex Number Optimization",
        "Sparse Floating-Point Constant Propagation", 
        "Inline Floating-Point Functions",
        "Math Library Call Optimization", 
        "Fused Multiply-Add (FMA) Optimization",
        "Handling Subnormal Numbers", 
        "Mixed Precision Arithmetic",
        "Floating-Point Constant Folding", 
        "Optimization of Floating-Point Comparisons",
        "Profile-Guided Floating-Point Optimization", 
        "Reduction of Floating-Point Error",
        "Rounding Mode Optimization", 
        "Floating-Point Range Analysis",
        "Memory Alignment for Floating-Point Arrays", 
        "Cache Optimization for Floating-Point Data",
        "Minimizing Register Spills in Floating-Point Operations", 
        "Speculative Execution of Floating-Point Operations"
    };

    public final String[] m_compilerParts = {
        "code generation", 
        "optimization passes", 
        "backend transformations",
        "backend", "Middle-end","object file manipulation",
        "Handles Abstract Syntax Tree (AST)",
        "Handles code generation", "Handles machine code generation", "Collection of optimization passes", 
        "GCC transformations",
        "Parses C code"
        };

    public final String[] m_conceptList = {
        "Robotics", "Mechanical Engineering", "Aerospace Engineering",
        "Computer Graphics", "Signal Processing", "Control Systems",
        "Physics Simulations", "Electrical Engineering", "Machine Learning",
        "Financial Modeling", "Geophysics", "Climate Modeling",
        "Astronomy", "Acoustics", "Gaming and Physics Engines",
        "Medical Imaging", "Renewable Energy", "Automotive Industry",
        "Biophysics", "Cryptography", "Virtual Reality",
        "Marine Engineering", "Telecommunications", "Structural Engineering",
        "Quantum Computing", "Material Science", "Chemical Engineering","Control Systems and Automation","Geospatial Analysis"
    };

    public final String[] m_PL = {
        "Loops with floating-point calculations for unrolling optimization.",
        "Vectorized operations on arrays of floating-point numbers.",
        "Various floating-point arithmetic operations, including addition, subtraction, multiplication, division, and modulus.",
        "Edge cases with denormalized numbers, NaNs, and infinities.",
        "Pragmas to control optimization strategies for specific code sections.",
        "Recursive functions involving floating-point calculations.",
        "Math library functions like sin(), cos(), and exp().",
        "Conditional statements with floating-point comparisons.",
        "Exception handling for overflow, underflow, and division by zero.",
        "underflow and overflow scenarios in floating-point calculations",
        "Use of volatile qualifiers to prevent unwanted optimizations of floating-point variables.",
        "Floating-point comparisons involving epsilon to test precision limits."


    };

    public final String[] m_CST = {
        "loops to repeatedly apply floating-point operations",
        "Use of conditions to handle specific floating-point cases like NaN, INFINITY, and subnormal numbers",
        "functions to handle calculations using long long, long double, double, and float types, allowing comparison of precision",
        "nested loops to amplify the effects of precision loss by repeatedly adjusting values",
        "loops to cast values between long double, double, float, and long long",
        "Use functions like sin(), cos(), sqrt(), log() in iterative processes",
        "switch Statements for Handling Different Edge Cases",
        "recursive functions that process floating-point numbers",
        "macros to define constants that can trigger constant folding",
        "Loops for repeated calculations",
        "type casting",
        "edge-case iterations.",
        "conditionals and switch statements for handling special values",
    };

    public final String[] m_edgeCase = {
        "Precision Loss in Arithmetic Operations",
        "Catastrophic Cancellation",
        "Different rounding modes (round to nearest, round toward zero, round toward infinity)",
        "Underflow and Gradual Underflow",
        "Overflow Handling",
        "Signaling and Quiet NaNs",
        "Comparing NaN with any number, including itself",
        "Infinity Arithmetic",
        "Special Values in long double",
        "Representation of -0.0",
        "Casting between float, double, long double, and integer types like long long",
        "Using constants like M_PI (π) and M_E (Euler’s number) with extreme values",
        "Multiplying or dividing by extremely large or small values"

    };


    private String getRandomEntry(String[] array) {
        // Check if the array is not empty
        if (array.length == 0) {
            return "Array is empty"; // or some appropriate value
        }

        int randomIndex = random.nextInt(array.length);
        return array[randomIndex];
    }

    public String getRandomCompilerOpt() {
        return getRandomEntry(m_compilerOpt);
    }

    public String getRandomConcept() {
        return getRandomEntry(m_conceptList);
    }
    public String getRandomCompilerParts() {
        return getRandomEntry(m_compilerParts);
    }
    public String getRandomPL() {
        return getRandomEntry(m_PL);
    }
    public String getRandomEC() {
        return getRandomEntry(m_edgeCase);
    }
    public String getRandomST() {
        return getRandomEntry(m_CST);
    }
}
