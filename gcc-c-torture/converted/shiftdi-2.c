/* { dg-require-effective-target longlong64 } */

long long a = 568513516876543756;
long long b = -754324895235774564;
unsigned long long c = 156789543257562457;

long long expected_a[64] = {568513516876543756, 1137027033753087512, 2274054067506175024, 4548108135012350048, 9096216270024700096, -254311533660151424, -508623067320302848, -1017246134640605696, -2034492269281211392, -4068984538562422784, -8137969077124845568, 2170805919459860480, 4341611838919720960, 8683223677839441920, -1080296718030667776, -2160593436061335552, -4321186872122671104, -8642373744245342208, 1161996585218867200, 2323993170437734400, 4647986340875468800, -9150771391958614016, 145201289792323584, 290402579584647168, 580805159169294336, 1161610318338588672, 2323220636677177344, 4646441273354354688, -9153861527000842240, 139021019707867136, 278042039415734272, 556084078831468544, 1112168157662937088, 2224336315325874176, 4448672630651748352, 8897345261303496704, -652053551102558208, -1304107102205116416, -2608214204410232832, -5216428408820465664, 8013887256068620288, -2418969561572311040, -4837939123144622080, 8770865827420307456, -905012418868936704, -1810024837737873408, -3620049675475746816, -7240099350951493632, 3966545371806564352, 7933090743613128704, -2580562586483294208, -5161125172966588416, 8124493727776374784, -2197756618156802048, -4395513236313604096, -8791026472627208192, 864691128455135232, 1729382256910270464, 3458764513820540928, 6917529027641081856, -4611686018427387904, -9223372036854775808ULL, 0, 0};
long long expected_b[64] = {-754324895235774564, -377162447617887282, -188581223808943641, -94290611904471821, -47145305952235911, -23572652976117956, -11786326488058978, -5893163244029489, -2946581622014745, -1473290811007373, -736645405503687, -368322702751844, -184161351375922, -92080675687961, -46040337843981, -23020168921991, -11510084460996, -5755042230498, -2877521115249, -1438760557625, -719380278813, -359690139407, -179845069704, -89922534852, -44961267426, -22480633713, -11240316857, -5620158429, -2810079215, -1405039608, -702519804, -351259902, -175629951, -87814976, -43907488, -21953744, -10976872, -5488436, -2744218, -1372109, -686055, -343028, -171514, -85757, -42879, -21440, -10720, -5360, -2680, -1340, -670, -335, -168, -84, -42, -21, -11, -6, -3, -2, -1, -1, -1, -1};
unsigned long long expected_c[64] = {156789543257562457, 78394771628781228, 39197385814390614, 19598692907195307, 9799346453597653, 4899673226798826, 2449836613399413, 1224918306699706, 612459153349853, 306229576674926, 153114788337463, 76557394168731, 38278697084365, 19139348542182, 9569674271091, 4784837135545, 2392418567772, 1196209283886, 598104641943, 299052320971, 149526160485, 74763080242, 37381540121, 18690770060, 9345385030, 4672692515, 2336346257, 1168173128, 584086564, 292043282, 146021641, 73010820, 36505410, 18252705, 9126352, 4563176, 2281588, 1140794, 570397, 285198, 142599, 71299, 35649, 17824, 8912, 4456, 2228, 1114, 557, 278, 139, 69, 34, 17, 8, 4, 2, 1, 0, 0, 0, 0, 0, 0};

int
main (void)
{
  int i;

  for (i = 0; i < 64; i++)
  {
    if ((a << i) != expected_a[i]
	|| (b >> i) != expected_b[i]
	|| (c >> i) != expected_c[i])
      __builtin_abort ();
  }
  printf("return "); 		return 0; 
}

