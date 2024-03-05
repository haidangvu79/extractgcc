// The specification below is based on the Frama-C standard library, with the
// added clause "no_underflow", which adds an extra precondition to detect
// the cases corresponding to "losing precision" in the TICTB specification.
/*@ requires finite_args: \is_finite(x) && \is_finite(y);
    requires finite_logic_res: \is_finite(pow(x, y));
    requires no_underflow: x != 0.0 ==> pow(x, y) != 0.0;
    assigns \result \from x, y;
    ensures finite_result: \is_finite(\result);
*/
extern double titcb_pow(double x, double y);
