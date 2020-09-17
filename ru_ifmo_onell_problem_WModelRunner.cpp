#include "ru_ifmo_onell_problem_WModelRunner.h"
#include <f_w_model_one_max.hpp>

JNIEXPORT jdouble JNICALL Java_ru_ifmo_onell_problem_WModelRunner_runWModel
  (JNIEnv *env, jobject jobj, jint jdimension, jdouble jdummy,
  jint jepistasis, jint jneutrality, jint jruggedness, jintArray jind) {
    W_Model_OneMax wm;
    wm.set_w_setting((double)jdummy, (int) jepistasis,(int) jneutrality, (int) jruggedness);
    wm.IOHprofiler_set_number_of_variables((int)jdimension);
    wm.reset_problem();
    wm.customize_optimal();
    jsize size = env->GetArrayLength( jind );
    std::vector<int> ind( size );
    env->GetIntArrayRegion(jind, jsize{0}, size, &ind[0] );
    return wm.evaluate(ind);
}

JNIEXPORT jdouble JNICALL Java_ru_ifmo_onell_problem_WModelRunner_getOptimum
  (JNIEnv *env, jobject jobj, jint jdimension, jdouble jdummy,
  jint jepistasis, jint jneutrality, jint jruggedness) {
    W_Model_OneMax wm;
    wm.set_w_setting((double)jdummy, (int) jepistasis,(int) jneutrality, (int) jruggedness);
    wm.IOHprofiler_set_number_of_variables((int)jdimension);
    wm.reset_problem();
    wm.customize_optimal();
    return wm.IOHprofiler_get_optimal()[0];

}
