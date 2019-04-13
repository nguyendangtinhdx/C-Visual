<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="text.aspx.cs" Inherits="text.text" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<asp:gridview runat="server"></asp:gridview>
<body>
    <form id="form1" runat="server">
    <div>
        <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" DataKeyNames="SoHoaDon,MaHang" DataSourceID="SqlDataSource1">
            <Columns>
                <asp:BoundField DataField="SoHoaDon" HeaderText="SoHoaDon" ReadOnly="True" SortExpression="SoHoaDon" />
                <asp:BoundField DataField="MaHang" HeaderText="MaHang" ReadOnly="True" SortExpression="MaHang" />
                <asp:BoundField DataField="SoLuong" HeaderText="SoLuong" SortExpression="SoLuong" />
                <asp:BoundField DataField="DonGia" HeaderText="DonGia" SortExpression="DonGia" />
            </Columns>
        </asp:GridView>
    
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:BánHàngConnectionString %>" SelectCommand="SELECT * FROM [HoaDon_MatHang]"></asp:SqlDataSource>
    
    </div>
    </form>
</body>
</html>
