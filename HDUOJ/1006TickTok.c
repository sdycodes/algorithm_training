#include <stdio.h>
//两两之间的相对速度
const double v_s2h = 360.0/60-360.0/43200, v_s2m = 360.0/60 - 360.0/3600, v_m2h = 360.0/3600-360.0/43200;	
//两两之间套圈时间 有一些古老的标准不允许常数定义中有常量标识符
const double c_s2h = 360.0/(360.0/60-360.0/43200), c_s2m = 360.0/(360.0/60 - 360.0/3600), c_m2h = 360.0/(360.0/3600-360.0/43200);	


double Max(double a, double b, double c){
	if(a>=b&&a>=c)	return a;
	if(b>=a&&b>=c)	return b;
	return c;
}

double Min(double a, double b, double c){
	if(a<=b&&a<=c)	return a;
	if(b<=a&&b<=c)	return b;
	return c;
}

int main(int argc, char *argv[]) {
	double D;
	while(scanf("%lf", &D)&&D>-0.5){
		double begin_s2h, begin_s2m, begin_m2h;
		double end_s2h, end_s2m, end_m2h;
		double total= 0;
		double tb_s2h, tb_s2m, tb_m2h, te_s2h, te_s2m, te_m2h;
		double left, right;
		
		begin_s2h = D/v_s2h;	//两两开始happy的时间 不算套圈
		begin_s2m = D/v_s2m;
		begin_m2h = D/v_m2h;
		
		end_s2h = (360-D)/v_s2h;	//两两结束happy的时间	不算套圈
		end_s2m = (360-D)/v_s2m;
		end_m2h = (360-D)/v_m2h;
		
		//考虑套圈 枚举	这里的加速技巧 1 循环次数少的在外层  这样内层被打破的收益更大  2 进行判断
		for(tb_m2h = begin_m2h, te_m2h = end_m2h; te_m2h<43200.0000001; te_m2h+=c_m2h, tb_m2h += c_m2h){
			for(tb_s2m = begin_s2m, te_s2m = end_s2m; te_s2m<43200.0000001; te_s2m+=c_s2m, tb_s2m += c_s2m){
				if(te_s2m<tb_m2h)	continue;	//内层的结束时间小于外层的开始 那应该再增加内层直至与外层重叠
				if(tb_s2m>te_m2h)	break;		//内层的开始时间已经超过了外层结束 那应该重新开始一个新的外层	增加此加速后为482ms
				for(tb_s2h = begin_s2h, te_s2h = end_s2h; te_s2h<43200.0000001; te_s2h+=c_s2h, tb_s2h += c_s2h){
					if(te_s2h<tb_m2h||te_s2h<tb_s2m)	continue;	//加速原理和之前一样	增加此加速为62ms
					if(tb_s2h>te_m2h||tb_s2h>te_s2m)	break;
					left = Max(tb_s2h, tb_s2m, tb_m2h);
					right = Min(te_s2h, te_s2m, te_m2h);
					if(left<right) total += (right-left);
				}
			}
		}
		printf("%.3f\n", total/432.0);
	}
	
}