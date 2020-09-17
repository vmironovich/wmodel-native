package ru.ifmo.onell.problem;

import java.util.ArrayList;

public class WModelRunner {
    native double runWModel(int dimension, double dummy, int epistasis,
    int neutrality, int ruggedness, int[] ind);

    native double getOptimum(int dimension, double dummy, int epistasis,
    int neutrality, int ruggedness);
    static {
        // $PROJECT_ROOT -- абсолютный путь до библиотеки
        System.loadLibrary("wmodel");
     }
}
