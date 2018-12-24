A*算法伪代码（在节点信息中记录了父节点）
OPEN表保存了所有已生成而未考察的节点，CLOSED表中记录已访问过的节点
open = [Start];
closed = [];
while open不为空{
	从open中取出估价值f最小的节点n
	if n == Rarget then
		return 从Start到n的路径
	else{
		for n的每个子节点x{
			if x in open{
				计算新的 f(x)
				比较open表中的旧 f(x)和新 f(x)
				if( 新f(x) < 旧f(x) ){
					删掉open表里的旧 f(x),加入新 f(x)
				}
			}  // 比较新f(x)和旧f(x) 实际上比的就是新旧g(x),因h(x)相等
			else if x in closed{
				计算新的 f(x)
				比较closed表中的旧 f(x) 和新 f(x)
				if 新 f(x) < 旧 f(x){
					remove x from closed
					add x to open 
				}
			}
			else{
				// x不在open，也不在close，是遇到的新结点
				计算 f(x) add x to open
			}
		}
	add n to closed
	}
}
//open表为空表示搜索结束了，那就意味着无解！
