<%@ page import="java.util.*,cms.dqm.workflow.*" %>
<%
  String mediaurl = WebUtils.GetEnv("media_url");
%>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>

  <meta http-equiv="content-type" content="text/html; charset=utf-8" />
  <title>CMS DQM Run Registry Data Cache</title>

  <link rel="stylesheet" type="text/css" href="<%=mediaurl%>index.css" />
  <link type="text/css" href="<%=mediaurl%>smoothness/jquery-ui-1.7.1.custom.css" rel="stylesheet" />

</head>
<body>

<h2>Current Run Registry Data Cache</h2>

<table border="1">
  <tr>
    <th>ID</th>
    <th>Mime</th>
    <th>Servlet</th>
    <th>Query</th>
    <th>Reads</th>
  </tr>
<%

  HashMap<String, CacheSyn.CacheItem> cache = CacheSyn.getInstance().getCachedItems();
  Set<String> keys = cache.keySet();
  Iterator<String> it = keys.iterator();
  while (it.hasNext()) {
    String id = it.next();
    CacheSyn.CacheItem item = cache.get(id);
%>
    <tr>
      <td><a href="<%=item.getUrl()%>"><%=id%></a></td>
      <td><%=item.getMime()%></td>
      <td><%=item.getServletName()%></td>
      <td><%=item.getQueryString()%></td>
      <td><%=item.getReads()%></td>
    </tr>
<%
  }
%>
</table>

Current syn is <%=CacheSyn.getInstance().getDataSyn()%>

</body>
</html>
