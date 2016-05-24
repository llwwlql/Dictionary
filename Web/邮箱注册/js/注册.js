var ch1,ch2,ch3,ch4;
function item(){
	var adr=document.getElementById("address");
	var str=adr.value;
	var myreg =/^[a-zA-Z]\w{5,17}$/;
	ch1=0;
	if(str.length==0)
	{
		document.getElementById("wrong-adr").innerHTML="6~18个字符，可使用字母、数字、下划线，需以字母开头";
		document.getElementById("wrong-adr").style.color="#aaa";
	}
	else if(str.length<6||str.length>18){
		document.getElementById("wrong-adr").innerHTML="长度应为6~18个字符 ";
		document.getElementById("wrong-adr").style.color="red";
	}else if((!myreg.test(str))){
		document.getElementById("wrong-adr").style.color="red";
		document.getElementById("wrong-adr").innerHTML="邮件地址需由字母、数字或下划线组成 ";
	}
	else{
		document.getElementById("wrong-adr").style.color="green";
		document.getElementById("wrong-adr").innerHTML="恭喜，该邮件地址可注册";
		ch1=1;
	}
}
function passChk(){
	var s = document.getElementById("password").value;
	ch2=0;
	if(s.length==0)
	{
		document.getElementById("wrong-pass").innerHTML="6~16个字符，区分大小写";
		document.getElementById("wrong-pass").style.color="#aaa";
	}
	else if(s.length<6||s.length>16){
		document.getElementById("wrong-pass").innerHTML="6~16个字符，区分大小写";
		document.getElementById("wrong-pass").style.color="red";
	}
	else{
		document.getElementById("wrong-pass").innerHTML="成功!";
		document.getElementById("wrong-pass").style.color="green";
		ch2=1;
	}
}
function repassChk(){
	var s1 = document.getElementById("re-password").value;
	var s2 = document.getElementById("password").value;
	ch3=0;
	if(s1!= s2){
		document.getElementById("wrong-repass").innerHTML="两次输入的密码不同，请重新输入";
		document.getElementById("wrong-repass").style.color="red";
	}
	else{
		document.getElementById("wrong-repass").innerHTML="成功!";
		document.getElementById("wrong-repass").style.color="green";
		ch3=1;
	}
}
function prov(){
	var im=document.getElementById("img-check");
	var str=document.getElementById("check").value;
	var str0="7nwk6";
	var str1="wc5ddx";
	var str2="fsmbsm";
	var str3="fdwxx";
	var str4="e9a3ph";
	ch4=0;
	if((im.name==0 && str==str0) || (im.name==1 && str==str1) || (im.name==2 && str==str2) || (im.name==3&& str==str3) || (im.name==4 && str==str4))
	{
		document.getElementById("font-check").innerHTML="验证成功！";
		document.getElementById("font-check").style.color="green";
		ch4=1;
	}
	else{
		document.getElementById("font-check").innerHTML="验证码错误！";
		document.getElementById("font-check").style.color="red";
		change(0);
	}
}
function change(peace){
	var im=document.getElementById("img-check");
	var rand=parseInt(Math.random()*1000)%5;
	var re=document.getElementById("check");
	im.src="img/验证码/"+rand+".jpg";
	im.name=rand;
	if(peace)
	{
		re.value="";
		document.getElementById("font-check").innerHTML="请填写图片中的字符，全输入小写";
		document.getElementById("font-check").style.color="#aaa";
	}
}
function sub(){
	if(ch1==1 && ch2==1 && ch3==1 && ch4==1)
	{
		alert("注册成功！");
		window.location.href="https://reg.163.com/logins.jsp";
	}
	else
		alert("输入信息错误！");
}