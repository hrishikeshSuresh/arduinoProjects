with open("humidity_csv.csv") as f:
	count=0
	in_time=0
	ex_time=0
	in_arr=[]
	ex_arr=[]
	date=[]
	temp=[]
	time=[]
	i=0
	j=0
	val=2
	#curr_hum=54.00
	for line in f:
		count+=1
		if(count != 1):
			string=line.split(",")
			string.remove("\n")
			#print(string)
			
			if(count==2):
				time.append(string[1])
				fp1=open("humidity_csv.csv","r")
				str1=fp1.readline()
				str2=fp1.readline()
				#print(str2)
				str3=str2.split(",")
				#print(str3)
				curr_hum=float(str3[3])
				#print("curr_hum:",curr_hum)
				fp1.close()
			if(val==2):
				if(abs(float(string[len(string)-1])-curr_hum )<=10):
					in_time+=1
				else:
					val=1	
			
			if(val==0):
				if(curr_ex_hum < float(string[len(string)-1])):
					ex_time+=1
				else:
					#curr_hum=float(string[len(string)-1])
					'''fp1=open("humidity_csv.csv","r")
					str2=fp1.readline()
					#print(str2)
					str3=str2.split(",")
					#print(str3)
					curr_hum=float(str2[3])
					fp1.close()'''
					ex_arr.append(ex_time)
					time.append(string[1])
					ex_time=0
					in_time=0
					val=2		
	
			if(val==1):
				in_arr.append(in_time)
				date.append(string[0])
				temp.append(string[2])
				in_time=0
				curr_ex_hum=float(string[len(string)-1])
				val=0
	print(in_arr)
	print(ex_arr)
	print(time)
	print(date)
	print(temp)			
	fp=open("inhale_exhale.sql","w")			
	for i in range(0,min(len(in_arr),len(ex_arr))):
		fp.write("db.inhale_exhale.insert({ date:\'"+date[i]+"\',time:\'"+time[i]+"\',temperature:"+temp[i]+",inhale_time:"+str(in_arr[i])+",exhale_time:"+str(ex_arr[i])+"})\n")
	fp.close()
	
	
	
	
	
			
