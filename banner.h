<!--한글-->
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<!-- script는 커뮤니티 관련 함수들, 커뮤니티 버튼 클릭시 커뮤니티 아래로 소제목이 생겨나는 함수 관련 코드-->
<script> 
var delay = 3;             
var m_length = 20;    
var sel_l_length = 30;
var sel_r_length = 60; 


var m_sel = 0;           
var m_max = 0;      
var sm_alpha = 0;   
var id = new Array();   
var sid = new Array();   
var m_top = 0;                
function on_load(){ 
    while(document.getElementById("menu"+(m_max+1)) != null){ 
        m_max++; 
        id[m_max] = document.getElementById("menu"+m_max); 
        sid[m_max] = document.getElementById("smenu"+m_max); 
    }; 
    m_top = id[1].offsetTop; 
    m_act(); 
} 
function m_over(m){ 
    m_sel = m; 
    for(i=1;i<=m_max;i++){ 
        if(sid[i] != null){ 
            if(m_sel == i){ 
                id[i].style.fontWeight = 'bold'; 
                sid[i].style.display = ""; 
                sm_alpha = 0; 
                if ((navigator.appName.indexOf('Microsoft')+1)) { 
                    sid[i].filters.alpha.opacity = sm_alpha; 
                }else{ 
                    sid[i].style.opacity = (sm_alpha/100); 
                } 
                sid[i].style.top = id[i].offsetTop + id[i].offsetHeight + 40; 
            }else{ 
                id[i].style.fontWeight = ''; 
                sid[i].style.display = "none"; 
            } 
        } 
    } 
} 
function m_act(){ 
    var goy = 0; 
    for(i=1;i<=m_max;i++){ 

        
        if(i>1) 
            temp = id[i-1].offsetWidth + id[i-1].offsetLeft; 
        if(i==1){ 
            gox=id[i].offsetLeft; 
        }else if(m_sel == i){ 
            gox =  temp + sel_l_length; 
        }else if(m_sel+1 == i){ 
            gox =temp + sel_r_length; 
        }else{ 
            gox = temp + m_length; 
        } 
        id[i].style.left = Math.ceil(id[i].offsetLeft - (id[i].offsetLeft - (gox))/delay)+"px"; 

       
        if(m_sel == i){ 
            id[i].style.top = Math.ceil(id[i].offsetTop - (id[i].offsetTop - (m_top + 7))/delay)+"px"; 
        }else if(m_sel!=0){ 
            id[i].style.top = Math.ceil(id[i].offsetTop - (id[i].offsetTop - (m_top - 5))/delay)+"px"; 
        } 

       
        if(m_sel == i && sid[i] != null){ 
            
            if(sm_alpha < 100){ 
                sm_alpha += 5; 
                if ((navigator.appName.indexOf('Microsoft')+1)) { 
                    sid[i].filters.alpha.opacity = sm_alpha; 
                }else{ 
                    sid[i].style.opacity = (sm_alpha/100); 
                } 
            } 
            
            goy = id[i].offsetTop + id[i].offsetHeight; 
            sid[i].style.top = (sid[i].offsetTop - (sid[i].offsetTop - goy)/delay)+"px"; 
        } 
    } 
    setTimeout('m_act()',20); 
} 
</script> 

<style> 
<!-- 커뮤니티 관련 스타일 지정 -->
	.sm_a{color: #666666; text-decoration:none; padding:0px 3px 0px 2px} 
	.sm_a:hover {color: #FFFFFF; text-decoration:none; background:#666666; padding:0px 3px 0px 2px} 
	.smenu{top:30px; position:absolute; filter:alpha(opacity=0);} 
	.mmenu{cursor:pointer; padding-right:2px; color:#FFFFFF} 
</style> 


<body onload='on_load()' background="images/header.png">
	
	
<!-- 상단 타이틀과 이미지 설정 -->
	<title>연대한국학교 수강신청</title>
	<link rel="SHORTCUT ICON" href="image/logo1.png"/>
	
<!-- 헤더의 메뉴 테이블 -->
	<table width = 100% bgcolor="#5587ED" height=145> <tr><td>
	<table width = 70% align = center>
		<tr  height = 120>
			<td align = 'left' width = 8% ><img src="image/logo1.png" ></td>
			<td align = 'left' width = 40%><a href=main.html><img src="image/ytks_as.png" ></a></td>
			<td align = 'right' width = 15%><img src="image/information.png" ></td>
			<td align = 'right' width = 15%><img src="image/save.png" ></td>
			<td align = 'right' width = 10%><img src="image/course.png" ></td>
			<td align = 'right' width = 12% class=mmenu id=menu1 onClick='m_over(1)'>
					<img src="image/community.png" ><br> 
					<div id='smenu1' class=smenu style=' display:none'>공지사항  |  묻고답하기  |  설문조사
					</div> 
			</td>
		</tr>
	
	</table>
	</td></tr>
	</table>
	<hr size = 5 color='#0D3EA3'>
</body>

